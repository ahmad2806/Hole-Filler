//
// Created by ahmad on 4/17/19.
//

#ifndef FILL_HOLE_IRUNNER_H
#define FILL_HOLE_IRUNNER_H

#include <iostream>
#include <vector>

#include "../fillHoleLibrary/HoleFillerLib.h"
#include "../fillHoleLibrary/connectivity/FourConnectivity.h"
#include "../fillHoleLibrary/connectivity/EightConnectivity.h"
#include "../fillHoleLibrary/connectivity/connectivityStore/ConnectivityStore.h"

#include "../view/cliView/CliView.h"
#include "../command/commandsStore/CommandsStore.h"

#include "../command/fillHoleCommand/FillHoleCommand.h"

class IRunner {
public:
//    the const for preventing the user from himself (prevent from doing greetClient = "something" )
    virtual const std::string& greetClient() = 0;
    virtual void start() = 0;
    virtual ~IRunner(){};

protected:
    CommandsStore m_commands_store;
    ConnectivityStore m_connectivity_store;
};


typedef SharedPtr<IRunner> IRunner_ptr;


#endif //FILL_HOLE_IRUNNER_H
