#ifndef CAMERAPROCESSOR_H
#define CAMERAPROCESSOR_H

#include <QObject>
#include "threadpoll.h"
#include <QImage>
#include "const.h"
#include <atomic>

// 检测处理器：接收 worker 出帧，投递到线程池做检测，检测结果回主线程发出。
// 线程亲和性：本对象工作在主线程，onFrameReady 由跨线程信号投递到主线程执行。
class CameraProcessor : public QObject
{
    Q_OBJECT
public:
    explicit CameraProcessor(QObject *parent = nullptr);
    void CvInvoke(std::shared_ptr<CameraFrame> image);   // 在线程池线程执行，检测并回主线程发结果

public slots:
    void onFrameReady(std::shared_ptr<CameraFrame> frame);   // 接收一帧（主线程执行）
    void stop();                            // 停止接收新帧

private:
    std::shared_ptr<CameraFrame> frame_;
    // 停止标志；同时复用为"单帧检测进行中"的防重入标记（同一时刻只处理一帧，其余丢帧）
    std::atomic<bool> stop_{false};

signals:
    void cv_finsh(QImage ,QImage);   // 检测完成信号（主线程发出）
};

#endif // CAMERAPROCESSOR_H
