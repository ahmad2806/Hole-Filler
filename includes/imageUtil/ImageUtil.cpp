//
// Created by ahmad on 4/20/19.
//

#include "ImageUtil.h"
#include "../../exceptions/ExceptionValidator.h"


cv::Mat
ImageUtil::combineTwoImages(const char image_path[], const char mask_path[], float hole_value) {

    float MAX_GRAY_SCALE_PIXEL_SIZE = 1.0f;
    unsigned char MAX_RGB_PIXEL_SIZE = 255;
    int THRESHOLD = 5;
    int ALPHA = 0;

    cv::Mat normal_image, mask_image, image;

    normal_image = readImage(image_path, cv::IMREAD_GRAYSCALE);
    mask_image = readImage(mask_path, cv::IMREAD_GRAYSCALE);

    ExceptionValidator::validateImagesSizes(mask_image.size(), normal_image.size());

    normal_image.convertTo(image, CV_32F, MAX_GRAY_SCALE_PIXEL_SIZE / MAX_RGB_PIXEL_SIZE, ALPHA);
    mask_image.setTo(0, mask_image < THRESHOLD);
    image.setTo(hole_value, mask_image);

    return image;
}


void ImageUtil::saveImage(cv::Mat &image, const std::string &path) {
    unsigned char MAX_RGB_PIXEL_SIZE = 255;

    image.convertTo(image, CV_8UC3, MAX_RGB_PIXEL_SIZE);
    cv::imwrite(path, image);
}

cv::Mat ImageUtil::readImage(const char *image_path, cv::ImreadModes mode) {
    cv::Mat image;
    image = cv::imread(image_path, mode);
    ExceptionValidator::validateEmptyImage(image, image_path);

    return image;
}
