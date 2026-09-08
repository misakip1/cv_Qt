#ifndef CVDISPATCHER_H
#define CVDISPATCHER_H
#include"cvinvoke.h"
#include<QJsonDocument>
#include<QJsonObject>

#include"const.h"
class cvDispatcher
{
public:
    cvDispatcher();
    static Defect execPix(QImage&image ,AlgorithmConfig);
};

#endif // CVDISPATCHER_H
