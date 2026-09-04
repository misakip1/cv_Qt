#include "cameramanager.h"
#include<QCamera>
CameraManager::CameraManager(QObject *parent)
    : QObject{parent}
{
    addDevice();
}

CameraManager::~CameraManager()
{
    // 析构前销毁所有还在运行的采集线程
    std::unique_lock<std::mutex> lk_(mtx_);
    QList<QString> s = camaer_thread_.keys();
    lk_.unlock();
    for (const auto& key : s)
    {
        removeWorker(key);
    }
    qDebug() << "mannger析构";
}

void CameraManager::addDevice()
{
    QList<QCameraDevice> li = QMediaDevices::videoInputs();
    for (auto& device : li)
    {
        if (map_[device.description()].isNull())
        {
            map_[device.description()] = device;
        }
    }
}

void CameraManager::addWorker(QString device_name)
{
    std::unique_lock<std::mutex> lk_(mtx_);
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

    // 创建 Worker（工作在采集线程）与处理器（工作在主线程

    CameraWorker* worker = new CameraWorker(map_[device_name]);


    QThread* thread = new QThread();
    CameraProcessor* processor_ = new CameraProcessor();

    // Worker 移动到采集线程
    worker->moveToThread(thread);

    // 线程启动后，在 worker 线程执行 start（创建相机并开始采集）
    // worker 出帧 -> 处理器（跨线程，AutoConnection 自动变 QueuedConnection，帧投递回主线程）
    connect(worker, &CameraWorker::frameReady, processor_, &CameraProcessor::onFrameReady);

    // 保存摄像头对应的 Worker 和线程
    camaer_thread_[device_name] = { device_name, worker, thread, processor_ };
    qDebug()<<"创建后camaer_thread_"<<camaer_thread_.size();
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
    qDebug()<<"删除后camaer_thread_"<<camaer_thread_.size();
    lk_.unlock();

    qDebug() << "[removeWorker] 1 begin" << device_name;

    // 1. 原子阻断帧流：主线程直接置停止标志，不依赖事件队列
    bool ok = QMetaObject::invokeMethod(item.worker,
                                        &CameraWorker::requestStop,
                                        Qt::BlockingQueuedConnection);
    qDebug() << "[removeWorker] 2 requestStop done";

    // 2. 停处理器，丢弃后续帧
    item.processor_->stop();
    qDebug() << "[removeWorker] 3 processor stop done";

    // 3. 退出采集线程事件循环并等待线程结束（finished 信号触发 stop 清理相机）
    item.thread->quit();
    qDebug() << "[removeWorker] 4 quit done";

    if(!item.thread->wait(1000))
    {
        item.thread->terminate();
        item.thread->wait();
    }
    qDebug() << "[removeWorker] 5 wait done";

    delete item.worker; // 相机对象已在采集线程内清理，此处为空壳
    qDebug() << "[removeWorker] 7 delete worker done";
    // 4. 清理对象
    delete item.thread;
    qDebug() << "[removeWorker] 6 delete thread done";


    delete item.processor_;      // 延迟删除，等待已投递的检测结果事件处理完
    qDebug() << "[removeWorker] 8 done";
}
