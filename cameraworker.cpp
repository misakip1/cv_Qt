#include "cameraworker.h"
#include<QThread>
#include"account_msg.h"
CameraWorker::CameraWorker(
    QCameraDevice device,
    QObject* parent)
    : QObject(parent),
    device_(device)
{

        qDebug() << "[worker ctor]"
                 << this
                 << "current =" << QThread::currentThread();

}

void CameraWorker::requestStop()
{
    stop_.store(true);
    qDebug() << "[worker] requestStop 调用, stop_=true";
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
    machine_code=Singleton<account_msg>::getInstance().getMsg().machine_code;
    user_name=Singleton<account_msg>::getInstance().getMsg().user_name;
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

    if (camera_)
        camera_->stop();
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
    captureTime = QDateTime::currentDateTime();
    camera_form_->captureTime = captureTime;
    camera_form_->image = frame.toImage();
    //先测试数据库，填充username
    camera_form_->user_name="wang";
    camera_form_->machine_code="1001";
    camera_form_->imageCode=imageCode_;

    imageCode_++;
    emit frameReady(camera_form_);
}
