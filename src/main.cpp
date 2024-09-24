#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 读取图片
    Mat img = imread("/home/xiewanhao/opencv_project/resources/test_image.png");
    if (img.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    // 转化为灰度图
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    imwrite("gray_image.png", gray); // 保存灰度图

    // 转化为 HSV 图片
    Mat hsv;
    cvtColor(img, hsv, COLOR_BGR2HSV);
    imwrite("hsv_image.png", hsv); // 保存 HSV 图

    // 显示结果
    imshow("Gray Image", gray);
    imshow("HSV Image", hsv);
    waitKey(0);

    // 读取图片
    Mat img = imread("/home/xiewanhao/opencv_project/resources/test_image.png");
    if (img.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    // 应用均值滤波
    Mat meanFiltered;
    blur(img, meanFiltered, Size(5, 5)); // 使用5x5的核

    // 应用高斯滤波
    Mat gaussianFiltered;
    GaussianBlur(img, gaussianFiltered, Size(5, 5), 0); // 使用5x5的核，标准差为0

    // 保存和显示结果
    imwrite("mean_filtered.png", meanFiltered);
    imwrite("gaussian_filtered.png", gaussianFiltered);

    imshow("Mean Filtered Image", meanFiltered);
    imshow("Gaussian Filtered Image", gaussianFiltered);

    // 读取图像
    Mat image = imread("/home/xiewanhao/opencv_project/resources/test_image.png"); // 替换为你的输入PNG图片路径
    if (image.empty()) {
        cout << "Could not open or find the image!" << endl;
        return -1;
    }

    // 转换到HSV颜色空间
    Mat hsvImage;
    cvtColor(image, hsvImage, COLOR_BGR2HSV);

    // 定义红色的HSV范围
    Scalar lowerRed1(0, 100, 100);   // 红色的低范围
    Scalar upperRed1(10, 255, 255);  // 红色的高范围
    Scalar lowerRed2(160, 100, 100); // 红色的第二低范围
    Scalar upperRed2(180, 255, 255); // 红色的第二高范围

    // 创建掩膜
    Mat mask1, mask2, mask;
    inRange(hsvImage, lowerRed1, upperRed1, mask1);
    inRange(hsvImage, lowerRed2, upperRed2, mask2);
    bitwise_or(mask1, mask2, mask);

    // 保存掩膜图像
    imwrite("mask.png", mask);

    // 寻找轮廓
    vector<vector<Point>> contours;
    findContours(mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // 在原图像上绘制轮廓
    Mat contourImage = image.clone();
    drawContours(contourImage, contours, -1, Scalar(0, 255, 0), 2); // 绿色轮廓
    imwrite("contours.png", contourImage);

    // 计算并绘制每个轮廓的bounding box
    Mat boundingBoxImage = image.clone();
    for (const auto& contour : contours) {
        Rect boundingBox = boundingRect(contour);
        rectangle(boundingBoxImage, boundingBox, Scalar(255, 0, 0), 2); // 蓝色bounding box
        double area = contourArea(contour);
        cout << "Contour Area: " << area << endl;
    }

    // 保存带bounding box的图像
    imwrite("bounding_boxes.png", boundingBoxImage);

    // 显示结果
    imshow("Original Image", image);
    imshow("Mask", mask);
    imshow("Contours", contourImage);
    imshow("Bounding Boxes", boundingBoxImage);

    // 加载图像
    Mat image = imread("/home/xiewanhao/opencv_project/resources/test_image.png");
    if (image.empty()) {
        cout << "Could not open or find the image!" << endl;
        return -1;
    }
    imwrite("original.png", image);

    //  颜色提取（红色区域）
    Mat hsv;
    cvtColor(image, hsv, COLOR_BGR2HSV);
    Scalar lower_red1(0, 100, 100);
    Scalar upper_red1(10, 255, 255);
    Scalar lower_red2(160, 100, 100);
    Scalar upper_red2(180, 255, 255);

    Mat mask1, mask2, mask;
    inRange(hsv, lower_red1, upper_red1, mask1);
    inRange(hsv, lower_red2, upper_red2, mask2);
    mask = mask1 | mask2;
    imwrite("mask.png", mask);

    // 灰度化
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    Mat gray_masked;
    gray.copyTo(gray_masked, mask);
    imwrite("gray_masked.png", gray_masked);

    // 二值化
    Mat binary;
    threshold(gray_masked, binary, 0, 255, THRESH_BINARY + THRESH_OTSU);
    imwrite("binary.png", binary);

    // 膨胀
    Mat dilated;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(binary, dilated, kernel);
    imwrite("dilated.png", dilated);

    // 腐蚀
    Mat eroded;
    erode(dilated, eroded, kernel);
    imwrite("eroded.png", eroded);

    // 漫水处理
    Mat flooded = eroded.clone();
    floodFill(flooded, Point(0, 0), Scalar(255));
    flooded = ~flooded; // 反转颜色
    imwrite("flood_fill.png", flooded);

    // 显示结果
    imshow("Original Image", image);
    imshow("Mask", mask);
    imshow("Gray Masked", gray_masked);
    imshow("Binary", binary);
    imshow("Dilated", dilated);
    imshow("Eroded", eroded);
    imshow("Flood Fill", flooded);

    // 绘制圆形
    Mat imageWithCircle = image.clone();
    Point center(200, 200); // 圆心坐标
    int radius = 50; // 半径
    Scalar circleColor(0, 255, 0); // 绿色
    circle(imageWithCircle, center, radius, circleColor, 2); // 线宽为2
    imwrite("circle.png", imageWithCircle); // 保存绘制圆形后的图像

    // 绘制方形
    Mat imageWithRectangle = image.clone();
    Point topLeft(100, 100); // 方形左上角坐标
    Point bottomRight(150, 150); // 方形右下角坐标
    Scalar rectColor(255, 0, 0); // 蓝色
    rectangle(imageWithRectangle, topLeft, bottomRight, rectColor, 2); // 线宽为2
    imwrite("rectangle.png", imageWithRectangle); // 保存绘制方形后的图像

    // 绘制文字
    Mat imageWithText = image.clone();
    String text = "OpenCV Drawing"; // 文字内容
    Point textOrg(100, 250); // 文字起始坐标
    Scalar textColor(255, 255, 255); // 白色
    int fontFace = FONT_HERSHEY_SIMPLEX;
    double fontScale = 1;
    int thickness = 2;
    putText(imageWithText, text, textOrg, fontFace, fontScale, textColor, thickness);
    imwrite("text.png", imageWithText); // 保存绘制文字后的图像

    // 找到红色区域的轮廓
    Mat hsvImage;
    cvtColor(image, hsvImage, COLOR_BGR2HSV);
    Scalar lowerRed1(0, 100, 100);
    Scalar upperRed1(10, 255, 255);
    Scalar lowerRed2(160, 100, 100);
    Scalar upperRed2(180, 255, 255);
    Mat mask1, mask2, mask;
    inRange(hsvImage, lowerRed1, upperRed1, mask1);
    inRange(hsvImage, lowerRed2, upperRed2, mask2);
    bitwise_or(mask1, mask2, mask);

    // 绘制红色外轮廓
    vector<vector<Point>> contours;
    findContours(mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    Mat imageWithContours = image.clone();
    for (const auto& contour : contours) {
        drawContours(imageWithContours, vector<vector<Point>>{contour}, -1, Scalar(0, 0, 255), 2); // 红色外轮廓
    }
    imwrite("contours.png", imageWithContours); // 保存绘制红色外轮廓后的图像

    // 绘制红色bounding box
    Mat imageWithBoundingBoxes = image.clone();
    for (const auto& contour : contours) {
        Rect boundingBox = boundingRect(contour);
        rectangle(imageWithBoundingBoxes, boundingBox, Scalar(0, 0, 255), 2); // 红色bounding box
    }
    imwrite("bounding_boxes.png", imageWithBoundingBoxes); // 保存绘制红色bounding box后的图像

    // 读取图像
    Mat image = imread("/home/xiewanhao/opencv_project/resources/test_image.png"); 
    if (image.empty()) {
        cout << "Could not open or find the image!" << endl;
        return -1;
    }

    // 图像旋转 35 度
    Point2f center(image.cols / 2.0, image.rows / 2.0);
    Mat rotationMatrix = getRotationMatrix2D(center, 35, 1.0); // 旋转中心、角度、缩放因子
    Mat rotatedImage;
    warpAffine(image, rotatedImage, rotationMatrix, image.size());
    imwrite("rotated.png", rotatedImage); // 保存旋转后的图像

    // 裁剪为左上角 1/4
    int newWidth = image.cols / 2;
    int newHeight = image.rows / 2;
    Rect roi(0, 0, newWidth, newHeight);
    Mat croppedImage = image(roi);
    imwrite("cropped.png", croppedImage); // 保存裁剪后的图像

    // 显示结果
    imshow("Original Image", image);
    imshow("Rotated Image", rotatedImage);
    imshow("Cropped Image", croppedImage);

    return 0;
}