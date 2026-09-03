#include "cameramanager.h"

CameraManager::CameraManager(QObject *parent)
    : QObject{parent}
{
    addDevice();
}

CameraManager::~CameraManager()
{
    std::unique_lock<std::mutex> lk_(mtx_);
    QList<QString> s=camaer_thread_.keys();
    lk_.unlock();
    for(const auto& key : s)
    {
        removeWorker(key);
    }
    qDebug()<<"mannger析构";
}

void CameraManager::addDevice()
{
    QList<QCameraDevice> li=QMediaDevices::videoInputs();
    for(auto&device:li)
    { if(map_[device.description()].isNull())
        {
            map_[device.description()]=device;
        }
    }
}

void CameraManager::addWorker(QString device_name)
{    std::unique_lock<std::mutex> lk_(mtx_);
    if (!map_.contains(device_name))
    {
        qDebug() << "没有找到摄像头:" << device_name;
        return;
    }

    // 防止重复创建同一个摄像头
    if (camaer_thread_.contains(device_name))
    {
            qDebug() << "该摄像头已经创建 Worker:" << device_name;
            return;

    }

    // 创建 Worker
    CameraWorker* worker =
        new CameraWorker(map_[device_name]);
    // 创建线程
    QThread* thread = new QThread();
    CameraProcessor*processor_=new CameraProcessor();
    // Worker 移动到线程
    worker->moveToThread(thread);

    // 线程启动后开始采集
    connect(thread,
            &QThread::started,
            worker,
            &CameraWorker::start,Qt::QueuedConnection);
   // connect(worker,&CameraWorker::stop,thread,&QThread::)
    connect(worker,&CameraWorker::frameReady,processor_,&CameraProcessor::onFrameReady);
    // 保存摄像头对应的 Worker 和线程
    camaer_thread_[device_name]={
        device_name,
        worker,
        thread,
        processor_
    };

    // 启动线程
    thread->start();

}

void CameraManager::removeWorker(QString device_name)
{
    std::unique_lock<std::mutex> lk_(mtx_);
    if (!camaer_thread_.contains(device_name))
    {
        return;

    }
     auto item = camaer_thread_.take(device_name);
    lk_.unlock();
    item.worker->requestStop();
    item.processor_->stop();
    //跨线程调用
     QMetaObject::invokeMethod(item.worker, &CameraWorker::stop, Qt::QueuedConnection);
    item.thread->quit();
    item.thread->wait();
    delete item.thread;
     delete item.worker;
    delete item.processor_;
}
