////
//// Created by ahmad on 4/17/19.
////

#include "MainRunner.h"


MainRunner::MainRunner(const IView_ptr &_view) : m_p_view(_view) {

    ICommand_ptr command_b(new CommandB("fill_hole"));
    m_commands_store.addCommand(command_b);


    IPixelConnectivity_ptr p_c_four(new FourConnectivity("FOUR"));
    IPixelConnectivity_ptr p_c_eight(new EightConnectivity("EIGHT"));
    m_connectivity_store.addConnectivity(p_c_four);
    m_connectivity_store.addConnectivity(p_c_eight);

}

void splitData(const std::string &cmd_line, std::vector<std::string> &v_cmd_input, char delimiter = ' ') {
    if (cmd_line.empty()) {
//        if it was empty, then error will be handled in the main;
        v_cmd_input.push_back(" ");
    }
    std::stringstream cmd_line_stream(cmd_line);
    std::string word;

    while (std::getline(cmd_line_stream, word, delimiter)) {
        v_cmd_input.push_back(word);
    }
}

void MainRunner::start() {
    m_p_view->showMe(greetClient());
    std::vector<std::string> v_input;
    while (1) {
        v_input.clear();
        m_p_view->showMe(m_commands_store.getRegisteredCommandList(m_connectivity_store));


        std::string input = m_p_view->getInputFor(getInputForCommand());

        splitData(input, v_input);
        if (v_input[0] == "exit")
            break;
        ICommand_ptr cmd = m_commands_store.getCommand(0);
        try {
            cmd = m_commands_store.getCommand(v_input[0]);
            cmd->runCommand(v_input, m_connectivity_store);
        } catch (std::invalid_argument &e) {
            m_p_view->showMe(e.what());
            continue;
        }

        m_p_view->showMe("image was saved successfully\n");

    }


}