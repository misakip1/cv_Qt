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
 struct AccountMsg
{
    QString user_name;
    QString user_pwd;
    QString machine_code;
};
struct CameraFrame
{
    QString user_name;
    QString machine_code;
    QString cameraName;//相机名
    QString cameraCode;//相机编号

    QImage image;//截取的图片

    QDateTime captureTime;//时间戳
    qint64 imageCode;

};
// struct DetectionResult
// {
//     QImage image;//检测后的图像
//     bool success = false;//是否NG

//     bool defect = false;//是否有缺陷
// // 漏底
// //     擦花
// //         脏点
// //             喷流
// //                 漆泡
// //                     角位漏底
// //                         杂色
// //                             桔皮
//     QString defectType;//缺陷类型

//     QString message;//检测提示

//     qint64 processTime = 0;//检测时间

//     QString imagePath;//保存路径
// };
struct CameraTask
{
    // 原始采集信息
    QString user_name;
    QString machine_code;
    QString cameraName;//相机名
    QString cameraCode;//相机编号
    QString imageCode;
    QString image1_path;//截取的图片

    QString captureTime;//时间戳

    QString image2_path;//检测后的图像
    bool success = false;//是否NG

    bool defect = false;//是否有缺陷
    // 漏底
    //     擦花
    //         脏点
    //             喷流
    //                 漆泡
    //                     角位漏底
    //                         杂色
    //                             桔皮
    QString defectType;//缺陷类型

    QString message;//检测提示

    qint64 processTime = 0;//检测消耗时间

    QString imagePath;//保存路径
    QImage image1_;
    QImage image2_;

};
inline QString path="http://192.168.88.128:8080/";

#endif // CONST_H
