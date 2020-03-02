//
// Created by ahmad on 4/16/19.
//

#ifndef FILL_HOLE_CLIVIEW_H
#define FILL_HOLE_CLIVIEW_H

#include "../IView.h"

class CliView : public IView {

    inline void showMe(std::string to_print) ;
    inline std::string getInputFor(std::string msg);
};

void CliView::showMe(std::string to_print) {
    std::cout << to_print << std::endl;
}

std::string CliView::getInputFor(std::string msg) {
    std::cout << msg << std::endl;
    std::string s;
    getline(std::cin, s);
    return s;
}


#endif //FILL_HOLE_CLIVIEW_H
