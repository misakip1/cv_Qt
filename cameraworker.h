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
#include<QElapsedTimer>
#include <QImage>
#include <atomic>
#include "const.h"

// 相机采集 Worker：运行在独立 QThread 中，负责单个相机的创建、采集、出帧。
// 线程亲和性：本对象被 moveToThread 到采集线程，start/stop/onVideoFrameChanged 都在该线程执行。
class CameraWorker : public QObject
{
    Q_OBJECT

public:
    explicit CameraWorker(
        QCameraDevice device,
        QObject* parent = nullptr);


    void requestStop();
    ~CameraWorker();
public slots:
    void start();   // 采集线程执行：创建相机对象并开始采集
    void stop();    // 采集线程执行：停相机并清理相机对象

    void test();
private :
    void onVideoFrameChanged(
        const QVideoFrame& frame);

signals:
    void frameReady(
        std::shared_ptr<CameraFrame> frame);

    void cameraError(
        QString error);


private:
    QString user_name;
    QString machine_code;
    QString cameraName;       // 相机名
    QString cameraCode;       // 相机编号
    QDateTime captureTime;    // 时间戳
    qint64 imageCode_{0};
    QMediaCaptureSession* session_ = nullptr;
    QCamera* camera_ = nullptr;
    QCameraDevice device_;
    QVideoSink* videoSink_ = nullptr;
    std::shared_ptr<CameraFrame> camera_form_;
    QImageCapture* capture_ = nullptr;

    std::atomic<bool> stop_{false};   // 跨线程停止标志（原子，无锁）

};

#endif
