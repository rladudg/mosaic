#ifndef MOSAIC_H
#define MOSAIC_H

#include <opencv2/opencv.hpp>

void mosaic(cv::Mat& img, cv::Rect face, double scale = 0.05);

#endif // MOSAIC_H