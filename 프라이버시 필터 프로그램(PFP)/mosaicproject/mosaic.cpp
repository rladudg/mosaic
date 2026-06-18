#include "mosaic.h"
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;
void mosaic(cv::Mat& img, cv::Rect face, double scale) {
    cv::Mat faceROI = img(face);
    cv::Mat small;
    resize(faceROI, small, cv::Size(), scale, scale, cv::INTER_LINEAR);
    resize(small, faceROI, faceROI.size(), 0, 0, cv::INTER_NEAREST);
}
