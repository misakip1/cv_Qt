#include "account_msg.h"

account_msg::account_msg(QObject *parent)
    : QObject{parent}
{}

void account_msg::setMsg(AccountMsg& msg)
{
    std::lock_guard<std::mutex> lk_(mtx_);
    msg_.machine_code=msg.machine_code;
    msg_.user_name=msg.user_name;
    msg_.user_pwd=msg.user_pwd;
}

AccountMsg account_msg::getMsg()
{ std::lock_guard<std::mutex> lk_(mtx_);
    return msg_;
}
