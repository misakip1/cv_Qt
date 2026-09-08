#ifndef CVINVOKE_H
#define CVINVOKE_H
#include"const.h"
#include<vector>

class CvInvoke
{
public:
    CvInvoke();
    static cv::Mat getGray(cv::Mat mat);

    // 把缺陷最小外接矩形画到图上
    static void drawDefectBoxes(cv::Mat& image, const std::vector<cv::RotatedRect>& boxes,
                                const cv::Scalar& color = cv::Scalar(0, 0, 255));

    // 每个缺陷一个静态算法函数（桩函数，检测逻辑待实现）
    // 返回值：检出缺陷数量；boxes：该类型检出的最小外接矩形
    static int detectDeformation(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);     // 变形
    static int detectBroken(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);          // 驳口
    static int detectScuff(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);           // 擦花
    static int detectWhitePoint(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);      // 打白点
    static int detectColorDifference(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes); // 杂色
    static int detectGrindingMark(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);    // 打磨印
    static int detectPrimerReturn(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);    // 返底
    static int detectExposedBase(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);     // 漏底
    static int detectHangerMark(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);      // 挂具印
    static int detectDent(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);            // 碰凹
    static int detectScratch(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);         // 划伤
    static int detectCrater(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);          // 火山口
    static int detectOrangePeel(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);      // 桔皮
    static int detectAluminumChip(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);    // 铝屑
    static int detectSprayFlow(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);       // 喷流
    static int detectBubble(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);          // 气泡
    static int detectPit(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);             // 起坑
    static int detectCoarseTexture(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);   // 纹粗
    static int detectCoatingCrack(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);    // 涂层开裂
    static int detectDirt(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);            // 脏点
    static int detectAdhesion(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);        // 粘接
    static int detectPowderBump(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);      // 凸粉
    static int detectCoatingScratch(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);  // 喷涂划伤
    static int detectPushDamage(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);      // 推伤
    static int detectOil(const cv::Mat& mat, const cv::Mat& gray, std::vector<cv::RotatedRect>& boxes);             // 油印
};

#endif // CVINVOKE_H
