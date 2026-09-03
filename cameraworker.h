#ifndef CAMERAWORKER_H
#define CAMERAWORKER_H

#include <QObject>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QVideoSink>
#include <QVideoFrame>
#include <QMediaDevices>
#include <QCameraFormat>
#include <QDebug>
#include <QImageCapture>
#include<QImage>
#include "const.h"
#include <atomic>

class CameraWorker : public QObject
{
    Q_OBJECT

public:

    explicit CameraWorker(
        QCameraDevice device,
        QObject* parent = nullptr);

    void requestStop() { stop_.store(true); }

public slots:

    void start();
    void stop();

private slots:

    void onVideoFrameChanged(
        const QVideoFrame& frame);

signals:

    void frameReady(
       const CameraFrame frame);

    void cameraError(
        QString error);

private:
    QString cameraName;//相机名
    QString cameraCode;//相机编号
    QDateTime captureTime;//时间戳
    QMediaCaptureSession* session_ = nullptr;

    QCamera* camera_;

    QCameraDevice device_;

    QVideoSink* videoSink_;
    QImage image_;
    std::shared_ptr<CameraFrame> camera_form_;
    QImageCapture* capture_;
    std::atomic<bool> stop_{false};
};

#endif
