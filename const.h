#ifndef CONST_H
#define CONST_H
#include<QString>
#include<QImage>
#include<QDateTime>
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
    QString cameraName;//相机名
    QString cameraCode;//相机编号

    QImage image;//截取的图片

    QDateTime captureTime;//时间戳

};
struct DetectionResult
{
    QImage image;//检测后的图像
    bool success = false;//是否NG

    bool defect = false;//是否有缺陷

    QString defectType;//缺陷类型

    QString message;//检测提示

    qint64 processTime = 0;//检测时间

    QString imagePath;//保存路径
};
struct CameraTask
{
    // 原始采集信息
    CameraFrame frame;

    // 检测结果
    DetectionResult result;
};
inline QString path="http://192.168.88.128:8080/";

#endif // CONST_H
