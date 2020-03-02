//
// Created by ahmad on 4/17/19.
//

#ifndef FILL_HOLE_COMMANDSTORE_H
#define FILL_HOLE_COMMANDSTORE_H

#include <iostream>
#include <sstream>
#include <vector>
#include "../ICommand.h"
#include "../../exceptions/ExceptionValidator.h"

class CommandsStore {
public:
    inline void addCommand(ICommand_ptr);

    std::string getRegisteredCommandList(const ConnectivityStore &c_s);

    ICommand_ptr getCommand(const std::string &s);

    inline ICommand_ptr getCommand(const int &i);

private:
    std::vector<ICommand_ptr> m_commands_list;
};

void CommandsStore::addCommand(ICommand_ptr command) {
    m_commands_list.push_back(command);
}


ICommand_ptr CommandsStore::getCommand(const int &i) {
    return m_commands_list[i];
}


#endif //FILL_HOLE_COMMANDSTORE_H
