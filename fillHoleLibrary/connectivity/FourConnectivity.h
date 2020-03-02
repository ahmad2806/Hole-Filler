//
// Created by ahmad on 4/18/19.
//

#ifndef FILL_HOLE_FOURCONNECTIVITY_H
#define FILL_HOLE_FOURCONNECTIVITY_H

#include "IPixelConnectivity.h"

class FourConnectivity : public IPixelConnectivity {
public:

    inline explicit FourConnectivity(const std::string & = "FOUR");
    inline const std::string& getName();
    inline std::vector<cv::Point> getNeighborsVector();

private:
    std::string m_name;
    std::vector<cv::Point> m_neighbors;
};

std::vector<cv::Point> FourConnectivity::getNeighborsVector() {
    return m_neighbors;
}

FourConnectivity::FourConnectivity(const std::string &name) : m_name(name) {

    m_neighbors.push_back(cv::Point(1, 0));
    m_neighbors.push_back(cv::Point(-1, 0));
    m_neighbors.push_back(cv::Point(0, 1));
    m_neighbors.push_back(cv::Point(0, -1));
}

const std::string &FourConnectivity::getName() {
    return m_name;
}


#endif //FILL_HOLE_FOURCONNECTIVITY_H
