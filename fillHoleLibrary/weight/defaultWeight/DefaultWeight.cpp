//
// Created by ahmad on 4/18/19.
//

#include "DefaultWeight.h"

DefaultWeight::DefaultWeight(float epsilon, float z) : m_epsilon(epsilon), m_z(z) {}

float DefaultWeight::getEuclideanDistance(const cv::Point &inside_hole, const cv::Point &boundary_hole) {
    int difference_x = inside_hole.x - boundary_hole.x;
    int difference_y = inside_hole.y - boundary_hole.y;
    double first_square = std::pow(difference_x, 2);
    double second_square = std::pow(difference_y, 2);
    double distance = std::sqrt(first_square + second_square);
    return (float) distance;
}