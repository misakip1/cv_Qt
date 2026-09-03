#include "cameraworker.h"
#include<QThread>
#include<QApplication>
CameraWorker::CameraWorker(
    QCameraDevice device,
    QObject* parent)
    : QObject(parent),
    device_(device)
{
    qDebug()<<"woker被创建";

}

void CameraWorker::requestStop()
{
    stop_.store(true);
    qDebug() << "[worker] requestStop 调用, stop_=true";
    if (camera_)
    {
        camera_->stop();
        QCoreApplication::processEvents(QEventLoop::AllEvents, 200);
    }
}

CameraWorker::~CameraWorker()
{

    delete camera_;
    delete videoSink_;
    delete capture_;
    delete session_;
    qDebug()<<"析构摄像头";

}
void CameraWorker::test()
{
    qDebug() << "[TEST] worker执行了"
             << "current =" << QThread::currentThread()
             << "affinity =" << this->thread();
}
void CameraWorker::start()
{
    // 本函数在采集线程执行
     qDebug() << "woker开始";
    stop_.store(false);
    if(!camera_)
    {
    camera_ = new QCamera(device_);
    cameraName = device_.description();
    cameraCode = device_.id();
    camera_form_ = std::make_shared<CameraFrame>();
    camera_form_->cameraCode = cameraCode;
    camera_form_->cameraName = cameraName;

    videoSink_ = new QVideoSink();
    capture_ = new QImageCapture();
    session_ = new QMediaCaptureSession();
    session_->setCamera(camera_);
    session_->setVideoSink(videoSink_);
    session_->setImageCapture(capture_);

    connect(videoSink_, &QVideoSink::videoFrameChanged,
            this, &CameraWorker::onVideoFrameChanged);
    }
    camera_->start();
    qDebug() << "[worker] start 完成, camera 已启动";
}

void CameraWorker::stop()
{   //相机暂停
    qDebug()<<"相机暂停";
    stop_.store(true);
    // 只停相机，不 delete。
    // 相机对象是 worker 的子对象，随主线程 delete worker 时统一析构；
    // 若在此（finished 信号内、事件循环已退出）同步 delete QCamera，
    // QCamera 析构要停内部后端线程却需要事件循环配合，会死锁导致 run() 不返回。
    if (camera_)
    {
        camera_->stop();

    }
}

void CameraWorker::onVideoFrameChanged(const QVideoFrame& frame)
{
    if (stop_.load()) {
        static std::atomic<int> shortCnt{0};
        if (videoSink_)
            disconnect(videoSink_, &QVideoSink::videoFrameChanged,
                       this, &CameraWorker::onVideoFrameChanged);
        if (camera_)
            camera_->stop();
        return;
    }

    image_ = frame.toImage();
    captureTime = QDateTime::currentDateTime();
    camera_form_->captureTime = captureTime;
    camera_form_->image = image_;
    emit frameReady(*camera_form_.get());
}
