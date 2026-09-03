#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <QObject>
#include "const.h"
#include <QMap>
#include <mutex>
#include <QCameraDevice>
#include <QMediaDevices>
#include <QList>
#include <QThread>
#include "cameraworker.h"
#include "cameraprocessor.h"

// 摄像头线程信息：记录每个摄像头对应的 worker、线程、处理器
struct camaer_thread
{
    QString camaer_name;
    CameraWorker* worker;
    QThread* thread;
    CameraProcessor* processor_;
};

// 相机管理器：负责枚举摄像头、创建/销毁采集线程。
// 线程亲和性：本对象工作在主线程，仅持有各线程的指针。
class CameraManager : public QObject
{
    Q_OBJECT
public:
    explicit CameraManager(QObject *parent = nullptr);
    ~CameraManager();

    void addDevice();
    void addWorker(QString device_name);
    void removeWorker(QString device_name);

    QMap<QString, camaer_thread> camaer_thread_;

private:
    QMap<QString, QCameraDevice> map_;   // 设备名 -> 设备
    std::mutex mtx_;                     // 保护 camaer_thread_ 的并发访问

signals:
};

#endif // CAMERAMANAGER_H
