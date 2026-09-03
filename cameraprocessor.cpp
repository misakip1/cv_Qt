#include "cameraprocessor.h"

CameraProcessor::CameraProcessor(QObject *parent)
    : QObject{parent},stop_(false)
{

}

 void CameraProcessor::CvInvoke(CameraFrame frame)
{
     CameraTask task;
    //检测过程
     task.frame=frame;
    emit cv_finsh(task);
}

void CameraProcessor::onFrameReady(CameraFrame frame)
{
    frame_=frame;
    if(stop_)
    {
        return;
    }
    stop_=true;
    ThreadPoll::getInstance().post([this, frame = std::move(frame)]() mutable {
        try {
            CvInvoke(std::move(frame)); // 执行检测
        } catch (...) {
            // 异常也要复位，否则死锁
            stop_.store(false);
            throw;
        }
        stop_.store(false); // 检测完成，复位标记
    });
}

void CameraProcessor::stop()
{
    stop_=true;

}
