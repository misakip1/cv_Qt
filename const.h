#ifndef CONST_H
#define CONST_H
#include<QString>
#include<QImage>
enum class Moudel
{
    RegModel=1001,
    ForgetModel=1002,
    LodingModel=1003
};
enum class ErrorCodes{
    SUCCESS=0,
    ERR_JSON=1,//解析失败
    ERR_NETWORK=2,
};
struct account_msg
{
    QString user_name;
    QString user_pwd;
    QString machine_code;

};
struct CameraFrame
{


};
inline QString path="http://192.168.88.128:8080/";

#endif // CONST_H
