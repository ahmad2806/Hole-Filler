//
// Created by ahmad on 4/18/19.
//

#ifndef FILL_HOLE_DEFAULTWEIGHT_H
#define FILL_HOLE_DEFAULTWEIGHT_H


#include "../IWeight.h"

class DefaultWeight : public IWeight {
public:
    DefaultWeight(float epsilon, float z);

    inline float calculateWeight(const cv::Point &, const cv::Point &);

private:
    static float getEuclideanDistance(const cv::Point &inside_hole, const cv::Point &boundary_hole);

    float m_epsilon;
    float m_z;
};

float DefaultWeight::calculateWeight(const cv::Point &u, const cv::Point &v) {
    return 1 / (std::pow(getEuclideanDistance(u, v), m_z) + m_epsilon);
}

#endif //FILL_HOLE_DEFAULTWEIGHT_H
