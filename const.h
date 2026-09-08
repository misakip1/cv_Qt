#ifndef CONST_H
#define CONST_H
#include<QString>
#include<QImage>
#include<QDateTime>
#include<QMessageBox>
#include<opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
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
struct AlgorithmConfig
{
    bool deformation;       // 变形
    bool broken;            // 驳口
    bool scuff;             // 擦花（擦伤）
    bool whitePoint;        // 打白点
    bool colorDifference;   // 杂色
    bool grindingMark;      // 打磨印
    bool primerReturn;      // 返底
    bool exposedBase;       // 漏底
    bool hangerMark;        // 挂具印
    bool dent;              // 碰凹
    bool scratch;           // 划伤
    bool crater;            // 火山口
    bool orangePeel;        // 桔皮
    bool aluminumChip;      // 铝屑
    bool sprayFlow;         // 喷流
    bool bubble;            // 气泡
    bool pit;               // 起坑
    bool coarseTexture;     // 纹粗
    bool coatingCrack;      // 涂层开裂
    bool dirt;              // 脏点
    bool adhesion;          // 粘接
    bool powderBump;        // 凸粉
    bool coatingScratch;    // 喷涂划伤
    bool pushDamage;        // 推伤
    bool oil;               // 油印
};
struct Defect
{
    bool success = false;//是否NG
    bool defect = false;//是否有缺陷
    QString defectType;//缺陷类型
    QString message;//检测提示
    qint64 processTime = 0;//检测消耗时间
    QImage image2_;
};

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
    QString defectType;//缺陷类型

    QString message;//检测提示

    qint64 processTime = 0;//检测消耗时间

    QString imagePath;//保存路径
    QImage image1_;
    QImage image2_;

};
inline QString path="http://192.168.88.128:8080/";
inline cv::Mat QImageToMat(const QImage& qImg)
{
    if (qImg.isNull())
        return {};

    if (qImg.format() != QImage::Format_RGBA8888_Premultiplied)
        return {};

    cv::Mat rgba(
        qImg.height(),
        qImg.width(),
        CV_8UC4
        );

    for (int y = 0; y < qImg.height(); ++y)
    {
        memcpy(
            rgba.ptr(y),
            qImg.constScanLine(y),
            static_cast<size_t>(qImg.width()) * 4
            );
    }

    return rgba;
}
inline QImage matToQImage(const cv::Mat& mat)
{
    if (mat.empty())
    {
        qDebug() << "matToQImage: mat empty";
        return {};
    }

    qDebug() << "matToQImage:"
             << "cols =" << mat.cols
             << "rows =" << mat.rows
             << "type =" << mat.type()
             << "channels =" << mat.channels()
             << "step =" << mat.step;

    // ============================================================
    // 单通道
    // ============================================================

    if (mat.channels() == 1)
    {
        QImage img(
            mat.cols,
            mat.rows,
            QImage::Format_Grayscale8
            );

        if (img.isNull())
        {
            qDebug() << "create grayscale QImage failed";
            return {};
        }

        for (int y = 0; y < mat.rows; ++y)
        {
            memcpy(
                img.scanLine(y),
                mat.ptr(y),
                static_cast<size_t>(mat.cols)
                );
        }

        qDebug() << "gray QImage:"
                 << img.size()
                 << img.isNull()
                 << img.bits();

        return img;
    }

    // ============================================================
    // 三通道 BGR
    // ============================================================

    if (mat.channels() == 3)
    {
        cv::Mat rgbMat;

        try
        {
            cv::cvtColor(
                mat,
                rgbMat,
                cv::COLOR_BGR2RGB
                );
        }
        catch (const cv::Exception& e)
        {
            qDebug() << "matToQImage cvtColor error:"
                     << e.what();

            return {};
        }

        if (rgbMat.empty())
        {
            qDebug() << "rgbMat empty";
            return {};
        }

        QImage img(
            rgbMat.cols,
            rgbMat.rows,
            QImage::Format_RGB888
            );

        if (img.isNull())
        {
            qDebug() << "create RGB QImage failed";
            return {};
        }

        for (int y = 0; y < rgbMat.rows; ++y)
        {
            memcpy(
                img.scanLine(y),
                rgbMat.ptr(y),
                static_cast<size_t>(rgbMat.cols) * 3
                );
        }

        qDebug() << "RGB QImage:"
                 << img.size()
                 << img.isNull()
                 << img.bits();

        return img;
    }

    // ============================================================
    // 四通道
    // ============================================================

    if (mat.channels() == 4)
    {
        cv::Mat rgbaMat;

        try
        {
            cv::cvtColor(
                mat,
                rgbaMat,
                cv::COLOR_BGRA2RGBA
                );
        }
        catch (const cv::Exception& e)
        {
            qDebug() << "4 channel cvtColor error:"
                     << e.what();

            return {};
        }

        QImage img(
            rgbaMat.cols,
            rgbaMat.rows,
            QImage::Format_RGBA8888
            );

        if (img.isNull())
        {
            qDebug() << "create RGBA QImage failed";
            return {};
        }

        for (int y = 0; y < rgbaMat.rows; ++y)
        {
            memcpy(
                img.scanLine(y),
                rgbaMat.ptr(y),
                static_cast<size_t>(rgbaMat.cols) * 4
                );
        }

        qDebug() << "RGBA QImage:"
                 << img.size()
                 << img.isNull()
                 << img.bits();

        return img;
    }

    qDebug() << "unsupported channels:"
             << mat.channels();

    return {};
}

#endif // CONST_H
