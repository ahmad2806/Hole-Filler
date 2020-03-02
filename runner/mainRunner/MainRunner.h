//
// Created by ahmad on 4/17/19.
//

#ifndef FILL_HOLE_MAINRUNNER_H
#define FILL_HOLE_MAINRUNNER_H

#include "../IRunner.h"

class MainRunner: public IRunner {
public:
    explicit MainRunner(const IView_ptr &);
    void start();
private:

    inline const std::string& greetClient();

    inline const std::string& getInputForCommand();

    IView_ptr m_p_view;

};

const std::string& MainRunner::greetClient() {
    static const std::string msg = "Hey,\nThanks for using me as your program runner\n";
    return msg;
}

const std::string &MainRunner::getInputForCommand() {
    static const std::string msg = "This is our command list, choose the command you want. insert exit to exit the program\n";
    return msg;

}

#endif //FILL_HOLE_MAINRUNNER_H
