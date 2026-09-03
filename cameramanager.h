#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <QObject>
#include"const.h"
#include<QMap>
#include<mutex>
#include<QCameraDevice>
#include<QMediaDevices>
#include<QList>
#include<QThread>
#include"cameraworker.h"
#include"cameraprocessor.h"
struct camaer_thread
{
    QString camaer_name;
    CameraWorker*worker;
    QThread*thread;
    CameraProcessor*processor_;
};

class CameraManager : public QObject
{
    Q_OBJECT
public:
    explicit CameraManager(QObject *parent = nullptr);
    ~CameraManager();
    void addDevice();
    void addWorker(QString device_name);
    void removeWorker(QString device_name);
    QMap<QString,camaer_thread> camaer_thread_;
private:
    QMap<QString,QCameraDevice> map_;

    std::mutex mtx_;

signals:
};

#endif // CAMERAMANAGER_H
