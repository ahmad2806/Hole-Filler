//
// Created by ahmad on 4/18/19.
//

#ifndef FILL_HOLE_EIGHTCONNECTIVITY_H
#define FILL_HOLE_EIGHTCONNECTIVITY_H


#include "IPixelConnectivity.h"

class EightConnectivity : public IPixelConnectivity {
public:
    inline explicit EightConnectivity(const std::string & = "EIGHT");

    inline const std::string &getName();

    inline std::vector<cv::Point> getNeighborsVector();

private:
    std::string m_name;
    std::vector<cv::Point> m_neighbors;
};

std::vector<cv::Point> EightConnectivity::getNeighborsVector() {
    return m_neighbors;
}

EightConnectivity::EightConnectivity(const std::string &name) : m_name(name) {
    m_neighbors.push_back(cv::Point(1, 0));
    m_neighbors.push_back(cv::Point(-1, 0));
    m_neighbors.push_back(cv::Point(0, 1));
    m_neighbors.push_back(cv::Point(0, -1));
    m_neighbors.push_back(cv::Point(1, 1));
    m_neighbors.push_back(cv::Point(-1, -1));
    m_neighbors.push_back(cv::Point(-1, 1));
    m_neighbors.push_back(cv::Point(1, -1));
}

const std::string &EightConnectivity::getName() {
    return m_name;
}


#endif //FILL_HOLE_EIGHTCONNECTIVITY_H
