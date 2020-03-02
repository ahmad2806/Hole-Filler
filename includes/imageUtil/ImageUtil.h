//
// Created by ahmad on 4/16/19.
//

#ifndef FILL_HOLE_IMAGEUTIL_H
#define FILL_HOLE_IMAGEUTIL_H


#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>

namespace ImageUtil {

    void saveImage(cv::Mat &image, const std::string &path = "./images/result.jpg");

    cv::Mat combineTwoImages(const char image_path[], const char mask_path[], float hole_value = -1);

    cv::Mat readImage(const char image_path[], cv::ImreadModes mode = cv::IMREAD_GRAYSCALE);
}




#endif //FILLHOLE_IMAGE_H


