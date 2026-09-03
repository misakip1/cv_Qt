#include "cameraprocessor.h"

CameraProcessor::CameraProcessor(QObject *parent)
    : QObject{parent}
{
}

void CameraProcessor::CvInvoke(CameraFrame frame)
{
    CameraTask task;
    task.frame = std::move(frame);

    // 本函数在线程池线程执行，直接 emit cv_finsh 会因 AutoConnection 变 DirectConnection
    // 在线程池线程直接操作 UI（Form::showPix 里的 setPixmap），属非法跨线程 UI 访问。
    // 因此把结果投递回主线程（this 的线程亲和）再发出。
    QMetaObject::invokeMethod(this, [this, task = std::move(task)]() mutable {
        emit cv_finsh(std::move(task));
    }, Qt::QueuedConnection);
}

void CameraProcessor::onFrameReady(CameraFrame frame)
{
    frame_ = frame;
    if (stop_.load())
        return;               // 已停止，丢弃新帧

    stop_.store(true);        // 标记"检测进行中"，同一时刻只处理一帧（丢帧）
    ThreadPoll::getInstance().post([this, frame = std::move(frame)]() mutable {
        try {
            CvInvoke(std::move(frame));
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
