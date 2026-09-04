#include "sqlmanager.h"
#include<QDir>
SQLManager::SQLManager(QObject *parent)
    : QObject{parent}
{

     thread_=std::thread([this](){
        this->run();
    });
}

void SQLManager::run()
{

    if (!initDatabase())
    {
        qDebug() << "Database init failed";
        return;
    }//初始化数据库
    initImagePath();//初始化保存地址
    constexpr size_t MAX_BATCH_SIZE = 50;
    constexpr auto MAX_WAIT_TIME =
        std::chrono::milliseconds(500);
//首先有数据来或者类结束唤醒，然后如果是类结束并且队列里面没有数据直接终止，
//第一条数据以后如果队列没满，进入循环等待新数据，如果已经满了直接结束等待进入投递数据库
//如果没有满cv挂起，等待数据来唤醒，数据来了就进入下一次循环拿数据，如果超时直接结束，投递数据库
    while(true)
    {
        std::vector<std::shared_ptr<CameraTask>> tasks_;
        {
        std::unique_lock<std::mutex> lk_(mtx_);
        cv_.wait(lk_,[this](){
            return stop_||!queue_.empty();
        });
        if(stop_.load()&&queue_.empty())
            return;
        auto deadline =
            std::chrono::steady_clock::now()
            + MAX_WAIT_TIME;

        while (tasks_.size() < MAX_BATCH_SIZE)
        {
            // 把当前队列中的数据拿走
            while (!queue_.empty() &&
                   tasks_.size() < MAX_BATCH_SIZE)
            {
                tasks_.push_back(
                    queue_.front());

                queue_.pop();
            }

            // 已经达到50条
            if (tasks_.size() >= MAX_BATCH_SIZE)
                break;

            // 等待新的数据或者超时
            if (cv_.wait_until(
                    lk_,
                    deadline,
                    [this] {
                        return stop_ || !queue_.empty();
                    }))
            {
                if (stop_ && queue_.empty())
                    break;

                  continue;

            }
            // 500ms到了
            break;
        }
    }
        if (!tasks_.empty())
        {
            processTasks(tasks_);
        }
    }
    QString connectionName = db_.connectionName();

    if (db_.isOpen())
        db_.close();

    db_ = QSqlDatabase();

    QSqlDatabase::removeDatabase(connectionName);

}

void SQLManager::stop()
{
    stop_.store(true);
    cv_.notify_all();

    if (thread_.joinable())
    {
        thread_.join();
    }


}

bool SQLManager::commitDb(std::vector<std::shared_ptr<CameraTask>> &tasks_)
{

    if (tasks_.empty())
    {qDebug()<<"队列为空无法保存数据库";
        return true;
    }

    if (!db_.isOpen())
    {
        qDebug() << "Database is not open:"
                 << db_.lastError().text();
        return false;
    }

    // =========================
    // 1. 开启事务
    // =========================

    if (!db_.transaction())
    {
        qDebug() << "Transaction begin failed:"
                 << db_.lastError().text();

        return false;
    }

    QSqlQuery query(db_);

    // =========================
    // 2. inspection_record
    // =========================

    const QString insertRecordSql = R"(
        INSERT INTO inspection_record (
            username,
            machine_no,
            camera_name,
            camera_code,
            original_image_path,
            processed_image_path,
            detect_time,
            detect_cost_ms
        )
        VALUES (
            :username,
            :machine_no,
            :camera_name,
            :camera_code,
            :original_image_path,
            :processed_image_path,
            :detect_time,
            :detect_cost_ms
        )
    )";

    if (!query.prepare(insertRecordSql))
    {
        qDebug() << "Prepare inspection_record failed:"
                 << query.lastError().text();

        db_.rollback();
        return false;
    }

    // =========================
    // 3. inspection_result
    // =========================

    QSqlQuery resultQuery(db_);

    const QString insertResultSql = R"(
        INSERT INTO inspection_result (
            inspection_id,
            is_ng,
            defect_type,
            detect_message
        )
        VALUES (
            :inspection_id,
            :is_ng,
            :defect_type,
            :detect_message
        )
    )";

    if (!resultQuery.prepare(insertResultSql))
    {
        qDebug() << "Prepare inspection_result failed:"
                 << resultQuery.lastError().text();

        db_.rollback();
        return false;
    }

    // =========================
    // 4. 批量插入
    // =========================

    for (const auto& task : tasks_)
    {
        if (!task)
            continue;

        // ---------------------------------
        // 插入 inspection_record
        // ---------------------------------

        query.bindValue(
            ":username",
            task->user_name);

        query.bindValue(
            ":machine_no",
            task->machine_code);

        query.bindValue(
            ":camera_name",
            task->cameraName);

        query.bindValue(
            ":camera_code",
            task->cameraCode);

        query.bindValue(
            ":original_image_path",
            task->image1_path);

        query.bindValue(
            ":processed_image_path",
            task->image2_path);

        query.bindValue(
            ":detect_time",
            task->captureTime);

        query.bindValue(
            ":detect_cost_ms",
            task->processTime);

        if (!query.exec())
        {
            qDebug() << "Insert inspection_record failed:"
                     << query.lastError().text();

            db_.rollback();
            return false;
        }

        // ---------------------------------
        // 获取刚插入记录的 ID
        // ---------------------------------

        QVariant inspectionId = query.lastInsertId();

        if (!inspectionId.isValid())
        {
            qDebug() << "Get inspection id failed";

            db_.rollback();
            return false;
        }

        // ---------------------------------
        // 插入 inspection_result
        // ---------------------------------

        resultQuery.bindValue(
            ":inspection_id",
            inspectionId);

        resultQuery.bindValue(
            ":is_ng",
            task->defect ? 1 : 0);

        resultQuery.bindValue(
            ":defect_type",
            task->defectType);

        resultQuery.bindValue(
            ":detect_message",
            task->message);

        if (!resultQuery.exec())
        {
            qDebug() << "Insert inspection_result failed:"
                     << resultQuery.lastError().text();

            db_.rollback();
            return false;
        }
    }

    // =========================
    // 5. 提交事务
    // =========================

    if (!db_.commit())
    {
        qDebug() << "Transaction commit failed:"
                 << db_.lastError().text();

        db_.rollback();
        return false;
    }

    return true;
}

bool SQLManager::initDatabase()
{
    const QString connectionName = "DetectionDatabase";

    db_ = QSqlDatabase::addDatabase(
        "QSQLITE",
        connectionName);

    db_.setDatabaseName(dbPath_);

    if (!db_.open())
    {
        qDebug() << "Open database failed:"
                 << db_.lastError().text();

        return false;
    }
    return true;
}

void SQLManager::initImagePath()
{
    QDir dir;
    QString rootDir = "./image";
    QString rawDir = rootDir + "/raw";
    QString resultDir = rootDir + "/result";
    if (!dir.exists(rawDir))
        dir.mkpath(rawDir);
    if (!dir.exists(resultDir))
        dir.mkpath(resultDir);
}

void SQLManager::processTasks(std::vector<std::shared_ptr<CameraTask>>& tasks)
{
    std::vector<std::shared_ptr<CameraTask>> trueSave;
    for (auto& task : tasks)
    {
        // 1. 保存图片
        if (!saveImage(task))
        {
            qDebug() << "Image save failed, skip database:"
                     << task->cameraName;

            continue;
        }

        // 2. 图片已经成功落盘
        trueSave.push_back(task);

    }

    // 3. 只有图片保存成功的任务才进入数据库

     commitDb(trueSave);

}

bool SQLManager::saveImage(std::shared_ptr<CameraTask> task_)
{


    bool ok1 = task_->image1_.save(task_->image1_path, "JPG", 80);
    bool ok2 = task_->image2_.save(task_->image2_path, "JPG", 80);
    qDebug()<<task_->image1_path<<"     "<<task_->image2_path;
    if(ok1&&ok2)
        return true;
    else
        return false;
}

void SQLManager::pushTask(std::shared_ptr<CameraTask> task)
{
    if(stop_.load()==true)
        return;
    {
        std::lock_guard<std::mutex> lock(mtx_);
        if(stop_.load()==true)
            return;
        queue_.push(task);
    }

    cv_.notify_one();
}
