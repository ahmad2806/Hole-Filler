//
// Created by ahmad on 4/17/19.
//

#ifndef FILL_HOLE_IVIEW_H
#define FILL_HOLE_IVIEW_H

#include <iostream>
#include "../fillHoleLibrary/sharedPtr/SharedPtr.h"

class IView {
public:
    virtual void showMe(std::string to_print) = 0;
    virtual std::string getInputFor(std::string) = 0;
    virtual ~IView(){};


};
typedef SharedPtr<IView> IView_ptr;




#endif //FILL_HOLE_IVIEW_H
