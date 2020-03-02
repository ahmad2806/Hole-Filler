//
// Created by ahmad on 4/18/19.
//

#ifndef FILL_HOLE_HOLEFILLERLIB_H
#define FILL_HOLE_HOLEFILLERLIB_H

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "weight/defaultWeight/DefaultWeight.h"
#include "connectivity/FourConnectivity.h"
#include "connectivity/IPixelConnectivity.h"
#include "weight/IWeight.h"

namespace HoleFillerLib {

    namespace Algorithms {
        cv::Mat
        fillHoleAlgo(cv::Mat &, const IPixelConnectivity_ptr &, const IWeight_ptr &, const float &hole_value = -1);

        cv::Mat fillHoleAlgo(cv::Mat &, const IPixelConnectivity_ptr &, float e, float z, const float &hole_value = -1);
    }
    namespace TracingAlgorithms {
        void findBoundaries(const cv::Mat &img, std::vector<cv::Point> &boundaries,
                            const std::vector<cv::Point> &v_connectivity, const float &hole_value);

        void findHoles(const cv::Mat &, std::vector<cv::Point> &hole, const float &hole_value);
    }
    namespace validator {
        inline bool isHole(const float &value, const float &hole_value);

        bool isBoundary(const cv::Mat &img, const int &row_pixel, const int &col_pixel,
                        const std::vector<cv::Point> &v_connectivity, const float &hole_value);
    }
}

bool HoleFillerLib::validator::isHole(const float &value, const float &hole_value) {
    return value == hole_value;
}


#endif //FILL_HOLE_HOLEFILLERLIB_H
