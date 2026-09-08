#include "cvdispatcher.h"

cvDispatcher::cvDispatcher() {}

Defect cvDispatcher::execPix( QImage& image_,
                              AlgorithmConfig  cfg_)
{
    const qint64 t1 = QDateTime::currentMSecsSinceEpoch();

    Defect defect;
    defect.success = false;
    defect.defect = false;
    defect.defectType.clear();
    defect.message.clear();
    defect.processTime = 0;
    defect.image2_ = image_;

    // ============================================================
    // 1. 检查输入图像
    // ============================================================

    if (image_.isNull())
    {
        defect.message = "输入图像为空";
        defect.processTime =
            QDateTime::currentMSecsSinceEpoch() - t1;
        return defect;
    }

    // ============================================================
    // 2. QImage -> cv::Mat
    // ============================================================

    cv::Mat image;
    cv::Mat gray;

    try
    {
        image = QImageToMat(image_);

        if (image.empty())
        {
            defect.message = "QImage转换cv::Mat失败";

            defect.processTime =
                QDateTime::currentMSecsSinceEpoch() - t1;

            return defect;
        }
        cv::pyrDown(image,image);
        gray = CvInvoke::getGray(image);

        if (gray.empty())
        {
            defect.message = "灰度图转换失败";

            defect.processTime =
                QDateTime::currentMSecsSinceEpoch() - t1;

            return defect;
        }
    }
    catch (const cv::Exception& e)
    {
        defect.message =
            QString("OpenCV异常: %1")
                .arg(QString::fromStdString(e.what()));

        defect.processTime =
            QDateTime::currentMSecsSinceEpoch() - t1;

        return defect;
    }
    catch (const std::exception& e)
    {
        defect.message =
            QString("标准异常: %1")
                .arg(QString::fromStdString(e.what()));

        defect.processTime =
            QDateTime::currentMSecsSinceEpoch() - t1;

        return defect;
    }
    catch (...)
    {
        defect.message = "未知异常";

        defect.processTime =
            QDateTime::currentMSecsSinceEpoch() - t1;

        return defect;
    }

    // ============================================================
    // 3. 算法定义
    // ============================================================

    struct Check
    {
        bool enabled;
        const char* name;

        int ( *fn )(
            const cv::Mat&,
            const cv::Mat&,
            std::vector<cv::RotatedRect>&
            );
    };

    const Check checks[] =
        {
            {
                cfg_.deformation,
                "变形",
                &CvInvoke::detectDeformation
            },

            {
                cfg_.broken,
                "断裂",
                &CvInvoke::detectBroken
            },

            {
                cfg_.scuff,
                "擦伤",
                &CvInvoke::detectScuff
            },

            {
                cfg_.whitePoint,
                "白点",
                &CvInvoke::detectWhitePoint
            },

            {
                cfg_.colorDifference,
                "色差",
                &CvInvoke::detectColorDifference
            },

            {
                cfg_.grindingMark,
                "打磨痕",
                &CvInvoke::detectGrindingMark
            },

            {
                cfg_.primerReturn,
                "底漆返出",
                &CvInvoke::detectPrimerReturn
            },

            {
                cfg_.exposedBase,
                "露底",
                &CvInvoke::detectExposedBase
            },

            {
                cfg_.hangerMark,
                "挂具痕",
                &CvInvoke::detectHangerMark
            },

            {
                cfg_.dent,
                "凹坑",
                &CvInvoke::detectDent
            },

            {
                cfg_.scratch,
                "划痕",
                &CvInvoke::detectScratch
            },

            {
                cfg_.crater,
                "火山口",
                &CvInvoke::detectCrater
            },

            {
                cfg_.orangePeel,
                "橘皮",
                &CvInvoke::detectOrangePeel
            },

            {
                cfg_.aluminumChip,
                "铝屑",
                &CvInvoke::detectAluminumChip
            },

            {
                cfg_.sprayFlow,
                "喷涂流痕",
                &CvInvoke::detectSprayFlow
            },

            {
                cfg_.bubble,
                "气泡",
                &CvInvoke::detectBubble
            },

            {
                cfg_.pit,
                "麻点",
                &CvInvoke::detectPit
            },

            {
                cfg_.coarseTexture,
                "粗纹",
                &CvInvoke::detectCoarseTexture
            },

            {
                cfg_.coatingCrack,
                "涂层裂纹",
                &CvInvoke::detectCoatingCrack
            },

            {
                cfg_.dirt,
                "脏污",
                &CvInvoke::detectDirt
            },

            {
                cfg_.adhesion,
                "附着物",
                &CvInvoke::detectAdhesion
            },

            {
                cfg_.powderBump,
                "粉末凸起",
                &CvInvoke::detectPowderBump
            },

            {
                cfg_.coatingScratch,
                "涂层划伤",
                &CvInvoke::detectCoatingScratch
            },

            {
                cfg_.pushDamage,
                "推伤",
                &CvInvoke::detectPushDamage
            },

            {
                cfg_.oil,
                "油印",
                &CvInvoke::detectOil
            }
        };

    // ============================================================
    // 4. 执行算法
    // ============================================================

    std::vector<cv::RotatedRect> allBoxes;

    bool algorithmError = false;

    QStringList defectTypes;
    QStringList messages;

    for (const auto& check : checks)
    {
        // 当前算法没有启用
        if (!check.enabled)
            continue;

        std::vector<cv::RotatedRect> boxes;

        try
        {
            const int count =
                check.fn(image, gray, boxes);

            if (count < 0)
            {
                algorithmError = true;

                messages.append(
                    QString("%1算法执行失败")
                        .arg(QString::fromUtf8(check.name))
                    );

                continue;
            }

            // ----------------------------------------------------
            // 检测到了缺陷
            // ----------------------------------------------------

            if (count > 0)
            {
                defect.defect = true;

                defectTypes.append(
                    QString::fromUtf8(check.name)
                    );

                messages.append(
                    QString("%1检测到%2处")
                        .arg(QString::fromUtf8(check.name))
                        .arg(count)
                    );

                allBoxes.insert(
                    allBoxes.end(),
                    boxes.begin(),
                    boxes.end()
                    );
            }
        }
        catch (const cv::Exception& e)
        {
            algorithmError = true;

            messages.append(
                QString("%1 OpenCV异常: %2")
                    .arg(QString::fromUtf8(check.name))
                    .arg(QString::fromStdString(e.what()))
                );
        }
        catch (const std::exception& e)
        {
            algorithmError = true;

            messages.append(
                QString("%1 标准异常: %2")
                    .arg(QString::fromUtf8(check.name))
                    .arg(QString::fromStdString(e.what()))
                );
        }
        catch (...)
        {
            algorithmError = true;

            messages.append(
                QString("%1 未知异常")
                    .arg(QString::fromUtf8(check.name))
                );
        }
    }

    // ============================================================
    // 5. 绘制检测框
    // ============================================================

    cv::Mat resultImage;

    try
    {
        // clone非常重要
        // 不直接修改image，避免后面出现数据共享问题
        resultImage = image.clone();

        if (!allBoxes.empty())
        {
            CvInvoke::drawDefectBoxes(
                resultImage,
                allBoxes
                );
        }
    }
    catch (const cv::Exception& e)
    {
        algorithmError = true;

        messages.append(
            QString("绘制缺陷框失败: %1")
                .arg(QString::fromStdString(e.what()))
            );
    }
    catch (...)
    {
        algorithmError = true;

        messages.append("绘制缺陷框发生未知异常");
    }

    // ============================================================
    // 6. cv::Mat -> QImage
    // ============================================================

    try
    {
        if (!resultImage.empty())
        {
            defect.image2_ =
                matToQImage(resultImage);
            qDebug()<< "image2"<<defect.image2_.bits();
        }
    }
    catch (const cv::Exception& e)
    {
        algorithmError = true;

        messages.append(
            QString("结果图转换失败: %1")
                .arg(QString::fromStdString(e.what()))
            );
    }
    catch (...)
    {
        algorithmError = true;

        messages.append("结果图转换发生未知异常");
    }

    // ============================================================
    // 7. 计算耗时
    // ============================================================

    const qint64 t2 =
        QDateTime::currentMSecsSinceEpoch();

    defect.processTime = t2 - t1;

    // ============================================================
    // 8. 判断是否超过500ms
    // ============================================================

    if (defect.processTime > 500)
    {
        algorithmError = true;

        messages.append(
            QString("检测超时: %1 ms")
                .arg(defect.processTime)
            );
    }

    // ============================================================
    // 9. 设置缺陷类型
    // ============================================================

    if (!defectTypes.isEmpty())
    {
        defect.defectType =
            defectTypes.join("、");
    }
    else
    {
        defect.defectType.clear();
    }

    // ============================================================
    // 10. 设置最终状态
    // ============================================================

    if (algorithmError)
    {
        // 检测过程失败
        defect.success = false;

        defect.message =
            messages.join("\n");
    }
    else
    {
        // 检测过程成功
        defect.success = true;

        if (defect.defect)
        {
            // 产品NG
            defect.message =
                messages.join("\n");
        }
        else
        {
            // 产品OK
            defect.message = "OK";
        }
    }

    return defect;
}
