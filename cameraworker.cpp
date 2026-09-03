#include "cameraworker.h"
#include<QMessageBox>
CameraWorker::CameraWorker(
    QCameraDevice device,
    QObject* parent)
    : QObject(parent),
    device_(device)
{
    //可以通过device调帧率

}
void CameraWorker::start()
{
    camera_ = new QCamera(device_, this);
    cameraName=device_.description();
    cameraCode=device_.id();
    camera_form_=std::make_shared<CameraFrame>();

    camera_form_->cameraCode=cameraCode;
    camera_form_->cameraName=cameraName;
    videoSink_ = new QVideoSink(this);

    capture_ = new QImageCapture(this);

    session_ = new QMediaCaptureSession(this);

    session_->setCamera(camera_);

    session_->setVideoSink(videoSink_);

    session_->setImageCapture(capture_);

    connect(
        videoSink_,
        &QVideoSink::videoFrameChanged,
        this,
        &CameraWorker::onVideoFrameChanged
        );
    stop_.store(false);
    camera_->start();
}

void CameraWorker::stop()
{
    qDebug()<<"worker析构";
    stop_.store(true);

    if (camera_)
        camera_->stop();
}

void CameraWorker::onVideoFrameChanged(const QVideoFrame &frame)
{
    if (stop_.load()) {
        if (camera_) camera_->stop();
        return;
    }
    image_=frame.toImage();
    captureTime=QDateTime::currentDateTime();
    camera_form_->captureTime=captureTime;
    camera_form_->image=image_;
    emit frameReady(*camera_form_.get());
}
