#include "cameraprocessor.h"
#include<QDir>
#include"sqlmanager.h"
#include"cvdispatcher.h"
CameraProcessor::CameraProcessor(QObject *parent)
    : QObject{parent}
{

}

void CameraProcessor::CvInvoke(std::shared_ptr<CameraFrame> frame,AlgorithmConfig msg_)
{
    std::shared_ptr<CameraTask> task=std::make_shared<CameraTask>();
    task->user_name=frame->user_name;
    task->machine_code=frame->machine_code;
    task->cameraName=frame->cameraName;
    task->cameraCode=frame->cameraCode;
    task->captureTime=frame->captureTime.toString("yyyyMMdd_hhmmss_zzz");
    task->imageCode=QString("%1").arg(frame->imageCode);
    //检测过程
    task->image1_=frame->image;//原图
    //进行图像处理
    Defect def_=cvDispatcher::execPix(task->image1_,msg_);
    QString fileNameBody = QString("%1_%2_%3_%4_%5")
                               .arg(task->captureTime)
                               .arg(task->user_name)
                               .arg(task->machine_code)
                               .arg(task->cameraName)
                               .arg(task->imageCode);

    // 完整路径
     task->image1_path   = QString("./image/raw/%1.jpg").arg(fileNameBody);
     task->image2_path   = QString("./image/result/%1.jpg").arg(fileNameBody);
     task->defect=def_.defect;
     task->defectType=def_.defectType;
     task->image2_=def_.image2_;
     task->message=def_.message;
     task->processTime=def_.processTime;
    //耗时磁盘IO丢到专门消费的线程里面去,停掉做测试
    //Singleton<SQLManager>::getInstance().pushTask(task);
    QMetaObject::invokeMethod(this, [this,task]() mutable {
        emit cv_finsh(task);
    }, Qt::QueuedConnection);
}

void CameraProcessor::subPoll(std::shared_ptr<CameraFrame>  frame)
{
    if (active_tasks_.load() >= MAX_CONCURRENT) {

        return;
    }
    active_tasks_.fetch_add(1);
    ThreadPoll::getInstance().post([this, frame]() {
        try {
            CvInvoke(frame, config_);
        } catch (...) {

            active_tasks_.fetch_sub(1);
            tryProcessNext();
            return;
        }
        active_tasks_.fetch_sub(1);
        // 处理完成后从队列中拉取下一帧
        tryProcessNext();
    });
}

void CameraProcessor::tryProcessNext() {
    std::lock_guard<std::mutex> lock(queue_mutex_);
    if (queue_.empty()) return;
    if (active_tasks_.load() >= MAX_CONCURRENT) return;
    auto frame = queue_.front();
    queue_.pop();
    subPoll(frame);
}

void CameraProcessor::onFrameReady(std::shared_ptr<CameraFrame> frame)
{
    {
        std::lock_guard<std::mutex> lock(queue_mutex_);
        if (queue_.size() < MAX_QUEUE_SIZE) {
            queue_.push(frame);
            // 更新 FPS
            qint64 curT = m_timer.elapsed();
            m_timeList.append(curT);

            // 超出窗口大小，删掉最旧一帧
            if(m_timeList.size() > m_winSize)
            {
                m_timeList.removeFirst();
            }

            // 窗口填满之后才计算FPS
            if(m_timeList.size() >= 30)
            {
                qint64 deltaMs = m_timeList.last() - m_timeList.first();
                // 帧数 / 总秒数
                double fps = (m_timeList.size()-1) / (deltaMs / 1000.0);
                emit sendFps(fps);
            }

        } else {
            queue_.pop();
            queue_.push(frame);
            // 队列满，覆盖最旧帧
        }
    }
      tryProcessNext();

}

void CameraProcessor::stop()
{
    stop_.store(true);   // 停止接收新帧；已在检测中的任务不受影响
}

void CameraProcessor::setConfig(std::shared_ptr<AlgorithmConfig> msg)
{
    qDebug()<<"调度器设置配置信息";
    config_=*msg;
}
