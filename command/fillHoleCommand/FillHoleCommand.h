//
// Created by ahmad on 4/17/19.
//

#ifndef FILL_HOLE_COMMANDB_H
#define FILL_HOLE_COMMANDB_H


#include "../ICommand.h"

class CommandB : public ICommand {
public:

    explicit CommandB(const std::string &);

    const std::string &getCommandSpecification(const std::string &my_connectivity);

    inline const std::string &getCommandName();

    inline void setCommandName(std::string name);

    void runCommand(const std::vector<std::string> &v_cmd, const ConnectivityStore &c_s);

private:
    std::string m_name;
    unsigned m_command_line_words;

};


const std::string &CommandB::getCommandName() {
    return m_name;
}

void CommandB::setCommandName(std::string name) {
    m_name = name;
}


#endif //FILL_HOLE_COMMANDB_H
