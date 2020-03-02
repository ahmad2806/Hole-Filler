//
// Created by ahmad on 4/20/19.
//

#ifndef FILL_HOLE_EXCEPTIONVALIDATOR_H
#define FILL_HOLE_EXCEPTIONVALIDATOR_H

#include <opencv2/core/core.hpp>

#include <stdexcept>
#include <sstream>

namespace ExceptionValidator {
    namespace HelperMethods {
        float convertStringToFloat(const std::string &, int counter=0);
    }

    inline void validateImagesSizes(const cv::Size_<int> &f_size, const cv::Size_<int> &s_size);

    inline void validateEmptyImage(const cv::Mat &img, const std::string &image_path);

    inline void validateInputCount(unsigned size, unsigned words);

    inline float validateStringIsFloat(const std::string &s_number);

    inline void connectivityNotFound();

    inline void commandNotFound();


}

void ExceptionValidator::validateInputCount(unsigned size, unsigned words) {
    if (size != words)
        throw std::invalid_argument("make sure you fill all the fields correctly\n");
}

void ExceptionValidator::validateImagesSizes(const cv::Size_<int> &f_size, const cv::Size_<int> &s_size) {
    if ((f_size.width != s_size.width) || (f_size.height != s_size.height)) {
        throw std::invalid_argument("mask and image sizes are not equal \n");
    }
}

void ExceptionValidator::validateEmptyImage(const cv::Mat &img, const std::string &image_path) {

    if (img.empty()) {
        std::stringstream ss;
        ss << image_path << " is not a valid image, it seems to be empty or not available";
        throw std::invalid_argument(ss.str());

    }
}

float ExceptionValidator::validateStringIsFloat(const std::string &s_number) {
    return ExceptionValidator::HelperMethods::convertStringToFloat(s_number);
}
void ExceptionValidator::connectivityNotFound() {
    throw std::invalid_argument("connectivity not found in store\n");
}
void ExceptionValidator::commandNotFound() {
    throw std::invalid_argument("command not found in store\n");
}

#endif //FILL_HOLE_EXCEPTIONVALIDATOR_H
