#include "cvmgr.h"


cvMgr::cvMgr(QObject *parent)
    : QObject{parent}
{
    config_=std::make_shared<AlgorithmConfig>();
}

void cvMgr::setConfig(std::shared_ptr<AlgorithmConfig> msg_)
{
    qDebug()<<"已经传入cvMgr";
    config_=msg_;
    emit processorConfig(msg_);
}
