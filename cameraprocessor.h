#ifndef CAMERAPROCESSOR_H
#define CAMERAPROCESSOR_H

#include <QObject>
#include"threadpoll.h"
#include<QImage>
#include"const.h"
#include<atomic>
class CameraProcessor : public QObject
{
    Q_OBJECT
public:
    explicit CameraProcessor(QObject *parent = nullptr);
    void CvInvoke(CameraFrame image);
public slots:
    void onFrameReady(CameraFrame frame );
    void stop();
private:
    CameraFrame frame_;
    std::atomic<bool> stop_;
signals:
    void cv_finsh(CameraTask);
};

#endif // CAMERAPROCESSOR_H
