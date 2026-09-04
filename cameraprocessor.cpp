#include "cameraprocessor.h"
#include<QDir>
#include"sqlmanager.h"
CameraProcessor::CameraProcessor(QObject *parent)
    : QObject{parent}
{

}

void CameraProcessor::CvInvoke(std::shared_ptr<CameraFrame> frame)
{
    qint64 t1 = QDateTime::currentMSecsSinceEpoch();
    std::shared_ptr<CameraTask> task=std::make_shared<CameraTask>();
    task->user_name=frame->user_name;
    task->machine_code=frame->machine_code;
    task->cameraName=frame->cameraName;
    task->cameraCode=frame->cameraCode;
    task->captureTime=frame->captureTime.toString("yyyyMMdd_hhmmss_zzz");
    task->imageCode=QString("%1").arg(frame->imageCode);
    //检测过程







    //。。。。
    task->image1_=frame->image;//原图
    task->image2_= task->image1_;//模拟处理后的图
    QString fileNameBody = QString("%1_%2_%3_%4_%5")
                               .arg(task->captureTime)
                               .arg(task->user_name)
                               .arg(task->machine_code)
                               .arg(task->cameraName)
                               .arg(task->imageCode);

    // 完整路径
     task->image1_path   = QString("./image/raw/%1.jpg").arg(fileNameBody);
     task->image2_path   = QString("./image/result/%1.jpg").arg(fileNameBody);
    //耗时磁盘IO丢到专门消费的线程里面去,停掉做测试
   // Singleton<SQLManager>::getInstance().pushTask(task);
    qint64 t2 = QDateTime::currentMSecsSinceEpoch();
   task->processTime=t2-t1;
    QMetaObject::invokeMethod(this, [this,task]() mutable {
        emit cv_finsh(task->image1_,task->image2_);
    }, Qt::QueuedConnection);
}



void CameraProcessor::onFrameReady(std::shared_ptr<CameraFrame> frame)
{
    frame_ = frame;
    if (stop_.load())
        return;               // 已停止，丢弃新帧

    stop_.store(true);        // 标记"检测进行中"，同一时刻只处理一帧（丢帧）
    ThreadPoll::getInstance().post([this]() mutable {
        try {
            CvInvoke(this->frame_);
        } catch (...) {
            stop_.store(false);   // 异常也要复位，否则后续帧被永久丢弃
            throw;
        }
        stop_.store(false);       // 检测完成，复位
    });
}

void CameraProcessor::stop()
{
    stop_.store(true);   // 停止接收新帧；已在检测中的任务不受影响
}
