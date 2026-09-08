#include "cvinvoke.h"
namespace
{
// 二值图中提取符合面积范围的轮廓，并转换成旋转矩形
int contoursToBoxes(
    const cv::Mat& binary,
    std::vector<cv::RotatedRect>& boxes,
    double minArea = 10.0,
    double maxArea = 1e9)
{
    boxes.clear();

    if (binary.empty())
        return 0;

    std::vector<std::vector<cv::Point>> contours;

    cv::findContours(
        binary,
        contours,
        cv::RETR_EXTERNAL,
        cv::CHAIN_APPROX_SIMPLE
        );

    for (const auto& contour : contours)
    {
        double area = cv::contourArea(contour);

        if (area < minArea || area > maxArea)
            continue;

        if (contour.size() < 3)
            continue;

        boxes.push_back(cv::minAreaRect(contour));
    }

    return static_cast<int>(boxes.size());
}


// 形态学去噪
cv::Mat morphOpen(
    const cv::Mat& src,
    int ksize = 3)
{
    cv::Mat dst;

    cv::Mat kernel = cv::getStructuringElement(
        cv::MORPH_ELLIPSE,
        cv::Size(ksize, ksize)
        );

    cv::morphologyEx(
        src,
        dst,
        cv::MORPH_OPEN,
        kernel
        );

    return dst;
}


// 闭运算，连接断裂区域
cv::Mat morphClose(
    const cv::Mat& src,
    int ksize = 3)
{
    cv::Mat dst;

    cv::Mat kernel = cv::getStructuringElement(
        cv::MORPH_ELLIPSE,
        cv::Size(ksize, ksize)
        );

    cv::morphologyEx(
        src,
        dst,
        cv::MORPH_CLOSE,
        kernel
        );

    return dst;
}


// 灰度局部差异
cv::Mat localDifference(
    const cv::Mat& gray,
    int blurSize = 31)
{
    cv::Mat blur;
    cv::Mat diff;

    cv::GaussianBlur(
        gray,
        blur,
        cv::Size(blurSize, blurSize),
        0
        );

    cv::absdiff(gray, blur, diff);

    return diff;
}


// 根据 HSV 提取低饱和/高饱和区域
cv::Mat getSaturationMask(
    const cv::Mat& mat,
    int low,
    int high)
{
    cv::Mat hsv;
    cv::cvtColor(mat, hsv, cv::COLOR_BGR2HSV);

    std::vector<cv::Mat> channels;
    cv::split(hsv, channels);

    cv::Mat mask;

    cv::inRange(
        channels[1],
        cv::Scalar(low),
        cv::Scalar(high),
        mask
        );

    return mask;
}


// 根据亮度提取
cv::Mat getBrightnessMask(
    const cv::Mat& gray,
    int low,
    int high)
{
    cv::Mat mask;

    cv::inRange(
        gray,
        cv::Scalar(low),
        cv::Scalar(high),
        mask
        );

    return mask;
}
}
CvInvoke::CvInvoke() {}

cv::Mat CvInvoke::getGray(cv::Mat mat)
{
    cv::Mat gray;
    cv::cvtColor(mat,gray,cv::COLOR_BGR2GRAY);
    return gray;
}

void CvInvoke::drawDefectBoxes(cv::Mat& image, const std::vector<cv::RotatedRect>& boxes,
                               const cv::Scalar& color)
{
    for (const cv::RotatedRect& r : boxes)
    {
        cv::Point2f pts[4];
        r.points(pts);
        std::vector<cv::Point> contour;
        for (int i = 0; i < 4; ++i)
            contour.push_back(pts[i]);
        cv::polylines(image, contour, true, color, 2);
    }
}

int CvInvoke::detectDeformation(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    if (gray.empty())
        return 0;

    cv::Mat blur;
    cv::GaussianBlur(gray, blur, cv::Size(5, 5), 0);

    cv::Mat edge;
    cv::Canny(blur, edge, 50, 150);

    std::vector<std::vector<cv::Point>> contours;

    cv::findContours(
        edge,
        contours,
        cv::RETR_EXTERNAL,
        cv::CHAIN_APPROX_SIMPLE
        );

    for (const auto& contour : contours)
    {
        double area = cv::contourArea(contour);

        if (area < 500)
            continue;

        cv::Rect rect = cv::boundingRect(contour);

        double ratio =
            static_cast<double>(rect.width) /
            std::max(rect.height, 1);

        // 这里主要过滤明显异常形状
        if (ratio > 10.0 || ratio < 0.1)
            continue;

        boxes.push_back(cv::minAreaRect(contour));
    }

    return static_cast<int>(boxes.size());
}

int CvInvoke::detectBroken(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    if (gray.empty())
        return 0;

    cv::Mat edge;

    cv::Canny(gray, edge, 80, 180);

    cv::Mat kernel =
        cv::getStructuringElement(
            cv::MORPH_RECT,
            cv::Size(5, 5));

    cv::morphologyEx(
        edge,
        edge,
        cv::MORPH_CLOSE,
        kernel
        );

    return contoursToBoxes(
        edge,
        boxes,
        30,
        5000
        );
}

int CvInvoke::detectScuff(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat diff = localDifference(gray, 31);

    cv::threshold(
        diff,
        diff,
        18,
        255,
        cv::THRESH_BINARY
        );

    diff = morphOpen(diff, 3);

    return contoursToBoxes(
        diff,
        boxes,
        20,
        10000
        );
}

int CvInvoke::detectWhitePoint(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat mask;

    cv::threshold(
        gray,
        mask,
        220,
        255,
        cv::THRESH_BINARY
        );

    mask = morphOpen(mask, 3);

    return contoursToBoxes(
        mask,
        boxes,
        5,
        2000
        );
}
int CvInvoke::detectColorDifference(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat hsv;
    cv::cvtColor(
        mat,
        hsv,
        cv::COLOR_BGR2HSV
        );

    std::vector<cv::Mat> ch;
    cv::split(hsv, ch);

    cv::Mat blur;
    cv::GaussianBlur(
        ch[0],
        blur,
        cv::Size(31, 31),
        0
        );

    cv::Mat diff;
    cv::absdiff(ch[0], blur, diff);

    cv::threshold(
        diff,
        diff,
        10,
        255,
        cv::THRESH_BINARY
        );

    diff = morphOpen(diff, 5);

    return contoursToBoxes(
        diff,
        boxes,
        30,
        30000
        );
}

int CvInvoke::detectGrindingMark(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat blur;
    cv::GaussianBlur(
        gray,
        blur,
        cv::Size(15, 15),
        0
        );

    cv::Mat diff;
    cv::absdiff(gray, blur, diff);

    cv::threshold(
        diff,
        diff,
        20,
        255,
        cv::THRESH_BINARY
        );

    diff = morphOpen(diff, 5);

    return contoursToBoxes(
        diff,
        boxes,
        50,
        50000
        );
}

int CvInvoke::detectPrimerReturn(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat hsv;
    cv::cvtColor(mat, hsv, cv::COLOR_BGR2HSV);

    std::vector<cv::Mat> ch;
    cv::split(hsv, ch);

    cv::Mat mask;

    cv::threshold(
        ch[1],
        mask,
        40,
        255,
        cv::THRESH_BINARY
        );

    mask = morphOpen(mask, 5);
    mask = morphClose(mask, 7);

    return contoursToBoxes(
        mask,
        boxes,
        100,
        100000
        );
}

int CvInvoke::detectExposedBase(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat blur;
    cv::GaussianBlur(
        gray,
        blur,
        cv::Size(31, 31),
        0
        );

    cv::Mat diff;
    cv::absdiff(gray, blur, diff);

    cv::threshold(
        diff,
        diff,
        25,
        255,
        cv::THRESH_BINARY
        );

    diff = morphClose(diff, 7);

    return contoursToBoxes(
        diff,
        boxes,
        50,
        100000
        );
}
int CvInvoke::detectHangerMark(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat blur;
    cv::GaussianBlur(
        gray,
        blur,
        cv::Size(9, 9),
        0
        );

    cv::Mat diff;
    cv::absdiff(gray, blur, diff);

    cv::threshold(
        diff,
        diff,
        25,
        255,
        cv::THRESH_BINARY
        );

    diff = morphOpen(diff, 5);

    return contoursToBoxes(
        diff,
        boxes,
        30,
        5000
        );
}
int CvInvoke::detectDent(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat blur;
    cv::GaussianBlur(
        gray,
        blur,
        cv::Size(7, 7),
        0
        );

    cv::Mat edge;
    cv::Canny(
        blur,
        edge,
        40,
        120
        );

    edge = morphClose(edge, 5);

    return contoursToBoxes(
        edge,
        boxes,
        20,
        20000
        );
}
int CvInvoke::detectScratch(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat gradX;
    cv::Sobel(
        gray,
        gradX,
        CV_32F,
        1,
        0,
        3
        );

    cv::Mat absX;
    cv::convertScaleAbs(
        gradX,
        absX
        );

    cv::threshold(
        absX,
        absX,
        50,
        255,
        cv::THRESH_BINARY
        );

    absX = morphOpen(absX, 3);

    std::vector<std::vector<cv::Point>> contours;

    cv::findContours(
        absX,
        contours,
        cv::RETR_EXTERNAL,
        cv::CHAIN_APPROX_SIMPLE
        );

    for (const auto& c : contours)
    {
        double area = cv::contourArea(c);

        if (area < 20 || area > 20000)
            continue;

        cv::RotatedRect r =
            cv::minAreaRect(c);

        float w = r.size.width;
        float h = r.size.height;

        float ratio =
            std::max(w, h) /
            std::max(1.0f, std::min(w, h));

        // 细长结构
        if (ratio >= 3.0f)
            boxes.push_back(r);
    }

    return static_cast<int>(boxes.size());
}
int CvInvoke::detectCrater(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat mask;

    cv::threshold(
        gray,
        mask,
        70,
        255,
        cv::THRESH_BINARY_INV
        );

    mask = morphOpen(mask, 3);

    std::vector<std::vector<cv::Point>> contours;

    cv::findContours(
        mask,
        contours,
        cv::RETR_EXTERNAL,
        cv::CHAIN_APPROX_SIMPLE
        );

    for (const auto& c : contours)
    {
        double area = cv::contourArea(c);

        if (area < 10 || area > 3000)
            continue;

        double perimeter =
            cv::arcLength(c, true);

        if (perimeter <= 0)
            continue;

        double circularity =
            4.0 * CV_PI * area /
            (perimeter * perimeter);

        if (circularity > 0.5)
            boxes.push_back(
                cv::minAreaRect(c)
                );
    }

    return static_cast<int>(boxes.size());
}

int CvInvoke::detectOrangePeel(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat lap;

    cv::Laplacian(
        gray,
        lap,
        CV_16S,
        3
        );

    cv::Mat absLap;

    cv::convertScaleAbs(
        lap,
        absLap
        );

    cv::GaussianBlur(
        absLap,
        absLap,
        cv::Size(15, 15),
        0
        );

    cv::threshold(
        absLap,
        absLap,
        18,
        255,
        cv::THRESH_BINARY
        );

    absLap = morphClose(
        absLap,
        7
        );

    return contoursToBoxes(
        absLap,
        boxes,
        200,
        100000
        );
}
int CvInvoke::detectAluminumChip(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat mask;

    cv::threshold(
        gray,
        mask,
        230,
        255,
        cv::THRESH_BINARY
        );

    mask = morphOpen(mask, 3);

    return contoursToBoxes(
        mask,
        boxes,
        3,
        3000
        );
}

int CvInvoke::detectSprayFlow(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat grad;

    cv::Sobel(
        gray,
        grad,
        CV_16S,
        1,
        0,
        3
        );

    cv::convertScaleAbs(
        grad,
        grad
        );

    cv::threshold(
        grad,
        grad,
        45,
        255,
        cv::THRESH_BINARY
        );

    grad = morphOpen(grad, 3);

    std::vector<std::vector<cv::Point>> contours;

    cv::findContours(
        grad,
        contours,
        cv::RETR_EXTERNAL,
        cv::CHAIN_APPROX_SIMPLE
        );

    for (const auto& c : contours)
    {
        double area = cv::contourArea(c);

        if (area < 30 || area > 30000)
            continue;

        cv::RotatedRect r =
            cv::minAreaRect(c);

        float w = r.size.width;
        float h = r.size.height;

        float ratio =
            std::max(w, h) /
            std::max(1.0f, std::min(w, h));

        if (ratio > 4.0f)
            boxes.push_back(r);
    }

    return static_cast<int>(boxes.size());
}

int CvInvoke::detectBubble(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat blur;

    cv::GaussianBlur(
        gray,
        blur,
        cv::Size(9, 9),
        0
        );

    std::vector<cv::Vec3f> circles;

    cv::HoughCircles(
        blur,
        circles,
        cv::HOUGH_GRADIENT,
        1.2,
        15,
        100,
        30,
        2,
        100
        );

    for (const auto& c : circles)
    {
        float x = c[0];
        float y = c[1];
        float r = c[2];

        boxes.emplace_back(
            cv::Point2f(x, y),
            cv::Size2f(r * 2, r * 2),
            0
            );
    }

    return static_cast<int>(boxes.size());
}

int CvInvoke::detectPit(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat diff =
        localDifference(gray, 21);

    cv::threshold(
        diff,
        diff,
        20,
        255,
        cv::THRESH_BINARY
        );

    diff = morphOpen(diff, 3);

    return contoursToBoxes(
        diff,
        boxes,
        10,
        5000
        );
}
int CvInvoke::detectCoarseTexture(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat lap;

    cv::Laplacian(
        gray,
        lap,
        CV_16S,
        3
        );

    cv::convertScaleAbs(
        lap,
        lap
        );

    cv::GaussianBlur(
        lap,
        lap,
        cv::Size(21, 21),
        0
        );

    cv::threshold(
        lap,
        lap,
        15,
        255,
        cv::THRESH_BINARY
        );

    lap = morphClose(lap, 9);

    return contoursToBoxes(
        lap,
        boxes,
        300,
        200000
        );
}
int CvInvoke::detectCoatingCrack(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat edge;

    cv::Canny(
        gray,
        edge,
        60,
        150
        );

    cv::Mat kernel =
        cv::getStructuringElement(
            cv::MORPH_RECT,
            cv::Size(3, 3)
            );

    cv::morphologyEx(
        edge,
        edge,
        cv::MORPH_CLOSE,
        kernel
        );

    std::vector<std::vector<cv::Point>> contours;

    cv::findContours(
        edge,
        contours,
        cv::RETR_EXTERNAL,
        cv::CHAIN_APPROX_SIMPLE
        );

    for (const auto& c : contours)
    {
        if (c.size() < 5)
            continue;

        double area =
            cv::contourArea(c);

        if (area < 10)
            continue;

        cv::RotatedRect r =
            cv::minAreaRect(c);

        float w = r.size.width;
        float h = r.size.height;

        float ratio =
            std::max(w, h) /
            std::max(1.0f, std::min(w, h));

        if (ratio > 5.0f)
            boxes.push_back(r);
    }

    return static_cast<int>(boxes.size());
}

int CvInvoke::detectDirt(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat mask;

    cv::threshold(
        gray,
        mask,
        60,
        255,
        cv::THRESH_BINARY_INV
        );

    mask = morphOpen(mask, 3);

    return contoursToBoxes(
        mask,
        boxes,
        3,
        1500
        );
}
int CvInvoke::detectAdhesion(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat diff =
        localDifference(gray, 51);

    cv::threshold(
        diff,
        diff,
        15,
        255,
        cv::THRESH_BINARY
        );

    diff = morphClose(diff, 11);

    return contoursToBoxes(
        diff,
        boxes,
        200,
        200000
        );
}

int CvInvoke::detectPowderBump(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat blur;

    cv::GaussianBlur(
        gray,
        blur,
        cv::Size(11, 11),
        0
        );

    cv::Mat diff;

    cv::absdiff(
        gray,
        blur,
        diff
        );

    cv::threshold(
        diff,
        diff,
        18,
        255,
        cv::THRESH_BINARY
        );

    diff = morphOpen(diff, 3);

    return contoursToBoxes(
        diff,
        boxes,
        10,
        5000
        );
}
int CvInvoke::detectCoatingScratch(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat hsv;

    cv::cvtColor(
        mat,
        hsv,
        cv::COLOR_BGR2HSV
        );

    std::vector<cv::Mat> ch;
    cv::split(hsv, ch);

    cv::Mat grad;

    cv::Sobel(
        ch[2],
        grad,
        CV_16S,
        1,
        0,
        3
        );

    cv::convertScaleAbs(
        grad,
        grad
        );

    cv::threshold(
        grad,
        grad,
        40,
        255,
        cv::THRESH_BINARY
        );

    grad = morphOpen(grad, 3);

    return contoursToBoxes(
        grad,
        boxes,
        20,
        30000
        );
}
int CvInvoke::detectPushDamage(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat diff =
        localDifference(gray, 41);

    cv::threshold(
        diff,
        diff,
        25,
        255,
        cv::THRESH_BINARY
        );

    diff = morphClose(diff, 7);

    return contoursToBoxes(
        diff,
        boxes,
        50,
        50000
        );
}
int CvInvoke::detectOil(
    const cv::Mat& mat,
    const cv::Mat& gray,
    std::vector<cv::RotatedRect>& boxes)
{
    boxes.clear();

    cv::Mat hsv;

    cv::cvtColor(
        mat,
        hsv,
        cv::COLOR_BGR2HSV
        );

    std::vector<cv::Mat> ch;
    cv::split(hsv, ch);

    cv::Mat satBlur;

    cv::GaussianBlur(
        ch[1],
        satBlur,
        cv::Size(31, 31),
        0
        );

    cv::Mat diff;

    cv::absdiff(
        ch[1],
        satBlur,
        diff
        );

    cv::threshold(
        diff,
        diff,
        10,
        255,
        cv::THRESH_BINARY
        );

    diff = morphOpen(diff, 5);
    diff = morphClose(diff, 9);

    return contoursToBoxes(
        diff,
        boxes,
        30,
        100000
        );
}
