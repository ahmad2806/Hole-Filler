//
// Created by ahmad on 4/20/19.
//



#include "HoleFillerLib.h"


bool HoleFillerLib::validator::isBoundary(const cv::Mat &img, const int &row_pixel, const int &col_pixel,
                                          const std::vector<cv::Point> &v_connectivity, const float &hole_value) {
    unsigned i;
    int temp_row, temp_col;
    for (i = 0; i < v_connectivity.size(); ++i) {
        temp_row = row_pixel + v_connectivity[i].y;
        temp_col = col_pixel + v_connectivity[i].x;
        if (validator::isHole(img.at<float>(temp_row, temp_col), hole_value))
            return true;
    }
    return false;
}

void HoleFillerLib::TracingAlgorithms::findBoundaries(const cv::Mat &image, std::vector<cv::Point> &v_boundaries,
                                                      const std::vector<cv::Point> &v_connectivity,
                                                      const float &hole_value) {

    for (int i = 1; i < image.rows - 1; i++) {
        for (int j = 1; j < image.cols - 1; j++) {
            if (!validator::isHole(image.at<float>(i, j), hole_value)) {
                if (validator::isBoundary(image, i, j, v_connectivity, hole_value))
                    v_boundaries.push_back(cv::Point(i, j));
            }
            // can also fill the hole vector here, but this will break single responsibility for the function
        }
    }
}

void HoleFillerLib::TracingAlgorithms::findHoles(const cv::Mat &image,
                                                 std::vector<cv::Point> &v_hole, const float &hole_value) {
//    not efficient, but at least cover all cases.
    for (int i = 1; i < image.rows - 1; i++) {
        for (int j = 1; j < image.cols - 1; j++) {
            if (validator::isHole(image.at<float>(i, j), hole_value)) {
                v_hole.push_back(cv::Point(i, j));
            }
        }
    }
}


void interpolation(cv::Mat &image, const std::vector<cv::Point> &v_boundaries, const cv::Point &hole,
                   const IWeight_ptr &weight_ptr) {
    float interpolation_nominator = 0;
    float interpolation_denominator = 0;
    float weight_between_points;
    unsigned i;
    for (i = 0; i < v_boundaries.size(); ++i) {
        weight_between_points = weight_ptr->calculateWeight(hole, v_boundaries[i]);
        interpolation_nominator += weight_between_points * image.at<float>(v_boundaries[i].x, v_boundaries[i].y);
        interpolation_denominator += weight_between_points;
    }

    image.at<float>(hole.x, hole.y) = interpolation_nominator / interpolation_denominator;
}

cv::Mat HoleFillerLib::Algorithms::fillHoleAlgo(cv::Mat &image, const IPixelConnectivity_ptr &con_ptr,
                                                const IWeight_ptr &weight_ptr, const float &hole_value) {
    cv::Mat result_image;
    image.copyTo(result_image);

    std::vector<cv::Point> v_boundaries;
    TracingAlgorithms::findBoundaries(image, v_boundaries, con_ptr->getNeighborsVector(), hole_value);

    std::vector<cv::Point> v_hole;
    TracingAlgorithms::findHoles(image, v_hole, hole_value);

    unsigned i;
    for (i = 0; i < v_hole.size(); ++i) {
        interpolation(result_image, v_boundaries, v_hole[i], weight_ptr);
    }
    return result_image;
}

cv::Mat
HoleFillerLib::Algorithms::fillHoleAlgo(cv::Mat &image, const IPixelConnectivity_ptr &con_ptr, float e, float z,
                                        const float &hole_value) {
    IWeight_ptr weight_ptr(new DefaultWeight(e, z));
    return HoleFillerLib::Algorithms::fillHoleAlgo(image, con_ptr, weight_ptr, hole_value);
}

