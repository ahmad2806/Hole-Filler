//
// Created by ahmad on 4/17/19.
//

#ifndef FILL_HOLE_ICOMMAND_H
#define FILL_HOLE_ICOMMAND_H


#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

#include "../fillHoleLibrary/sharedPtr/SharedPtr.h"
#include "../fillHoleLibrary/connectivity/connectivityStore/ConnectivityStore.h"
#include "../exceptions/ExceptionValidator.h"
#include "../includes/imageUtil/ImageUtil.h"
#include "../fillHoleLibrary/HoleFillerLib.h"

class ICommand {
public:

    virtual ~ICommand() {};

    virtual const std::string &getCommandSpecification(const std::string &my_connectivity) = 0;

    virtual const std::string &getCommandName() = 0;

    virtual void setCommandName(std::string name) = 0;

    virtual void runCommand(const std::vector<std::string> &, const ConnectivityStore &) = 0;


};

typedef SharedPtr<ICommand> ICommand_ptr;


#endif //FILL_HOLE_ICOMMAND_H
