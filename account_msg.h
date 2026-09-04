#ifndef ACCOUNT_MSG_H
#define ACCOUNT_MSG_H

#include <QObject>
#include<mutex>
#include"Singleton.h"
#include"const.h"
class account_msg : public QObject,Singleton<account_msg>
{
    Q_OBJECT
    friend class Singleton<account_msg>;
    using Singleton<account_msg>::getInstance;
public:
    void setMsg(AccountMsg& msg);
    AccountMsg getMsg();
private:
    explicit account_msg(QObject *parent = nullptr);
    AccountMsg msg_;
    std::mutex mtx_;


signals:
};

#endif // ACCOUNT_MSG_H
