//
// Created by ahmad on 4/17/19.
//


#include "CommandsStore.h"

std::string CommandsStore::getRegisteredCommandList(const ConnectivityStore &c_s) {
    unsigned i;
    std::stringstream commands_list;
    std::string temp;
    for (i = 0; i < m_commands_list.size(); ++i) {
        commands_list << i + 1 << "- ";
        commands_list << m_commands_list[i]->getCommandName() << " ";
        commands_list << m_commands_list[i]->getCommandSpecification(c_s.getRegisteredConnectivityList());
        commands_list << "\n";
    }

    return commands_list.str();
}

ICommand_ptr CommandsStore::getCommand(const std::string &s) {
    unsigned i;
    for (i = 0; i < m_commands_list.size(); ++i) {
        if (m_commands_list[i]->getCommandName() != s) continue;
        return m_commands_list[i];
    }
    ExceptionValidator::commandNotFound();
    return m_commands_list[i];
}
