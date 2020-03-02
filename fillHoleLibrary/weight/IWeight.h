//
// Created by ahmad on 4/18/19.
//

#ifndef FILL_HOLE_IWEIGHT_H
#define FILL_HOLE_IWEIGHT_H

#include <opencv2/core/types.hpp>
#include "../sharedPtr/SharedPtr.h"

class IWeight {
public:
    virtual float calculateWeight(const cv::Point &,const cv::Point &) = 0;
    virtual ~IWeight(){};
};

typedef SharedPtr<IWeight> IWeight_ptr;


#endif //FILL_HOLE_IWEIGHT_H
