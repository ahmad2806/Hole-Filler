
///***
// * 1- get command from user
// * 2- parse command
// * 3- read images
// * 4- create connectivity
// * 5- calculate weight
// *
// * 6- run algo to find boudry
// * 7- run algo to find all the holes points
// * 8- run the algo to fill hole
// * ***/
///**
// * 1- validator -> namespace or class?
// * 2- is pixel class is needed?
// * 3- exceptions handler is a class or namespace?
// * 4-


/**
 * 1- welcome message ==> cli
 * 2- ask for input ===> cli
 *      and pass it to the controller to split it
 * 3- split the input in which the program can work with ==> controller
 * 4- create such command using factory maybe ==> command
 *
 * 5- run the command ==> controller
 *
 * **/

#include "view/cliView/CliView.h"
#include "runner/mainRunner/MainRunner.h"
int main() {
    IView_ptr p_v(new CliView());
    IRunner_ptr p_r(new MainRunner(p_v));

    p_r->start();
    return 0;
}

//g++ -ggdb `pkg-config --cflags opencv` -o `basename opencvtest.cpp .cpp` opencvtest.cpp `pkg-config --libs opencv`