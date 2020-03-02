//
// Created by ahmad on 4/18/19.
//

#ifndef FILL_HOLE_IPIXELCONNECTIVITY_H
#define FILL_HOLE_IPIXELCONNECTIVITY_H

#include <vector>
#include "../sharedPtr/SharedPtr.h"
#include <opencv2/core/types.hpp>

class IPixelConnectivity {
public :
    virtual std::vector<cv::Point> getNeighborsVector() = 0;

    virtual const std::string &getName() = 0;

    IPixelConnectivity() {};

    virtual ~IPixelConnectivity() {};
private:
//    all the objects that inherits this class are Non-copyable
    IPixelConnectivity(const IPixelConnectivity &other);

};

typedef SharedPtr<IPixelConnectivity> IPixelConnectivity_ptr;

#endif //FILL_HOLE_IPIXELCONNECTIVITY_H
