#ifndef CVMGR_H
#define CVMGR_H

#include <QObject>
#include"const.h"
class cvMgr : public QObject
{
    Q_OBJECT
public:
    explicit cvMgr(QObject *parent = nullptr);
public slots:
    void setConfig(std::shared_ptr<AlgorithmConfig> msg_);
private:
    std::shared_ptr<AlgorithmConfig> config_;
signals:
    void processorConfig(std::shared_ptr<AlgorithmConfig>);
};

#endif // CVMGR_H
