#ifndef SQLMANAGER_H
#define SQLMANAGER_H

#include <QObject>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<thread>
#include<queue>
#include<condition_variable>
#include<mutex>
#include<atomic>
#include<vector>
#include"const.h"
class SQLManager : public QObject
{
    Q_OBJECT
public:
    explicit SQLManager(QObject *parent = nullptr);
    void run();
    void stop();
    bool commitDb(std::vector<std::shared_ptr<CameraTask>> &tasks_);
    bool initDatabase();
    void initImagePath();
    void processTasks(std::vector<std::shared_ptr<CameraTask>>& tasks);
    bool saveImage(std::shared_ptr<CameraTask> task_);
public slots:
    void pushTask(std::shared_ptr<CameraTask> task);
private:

    std::queue<std::shared_ptr<CameraTask>> queue_;
    std::thread thread_;
    std::mutex mtx_;
    std::condition_variable cv_;
    std::atomic<bool> stop_;
    QSqlDatabase db_;
    QString dbPath_="E:\\sqlitDb\\my.db";
signals:
};

#endif // SQLMANAGER_H
