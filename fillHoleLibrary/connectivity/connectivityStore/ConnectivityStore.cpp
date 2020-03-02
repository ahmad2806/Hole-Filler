//
// Created by ahmad on 4/20/19.
//

#include "ConnectivityStore.h"

std::string ConnectivityStore::getRegisteredConnectivityList() const {
    unsigned i;
    std::stringstream ss_connectivity_list;
    std::string temp;
    ss_connectivity_list << "\n\tchoose one of the available connectivity by inserting it's name\n";
    for (i = 0; i < m_connectivity_list.size(); ++i) {
        ss_connectivity_list << "\t" << i + 1 << "- ";
        ss_connectivity_list << m_connectivity_list[i]->getName();
        ss_connectivity_list << "\n";
    }

    return ss_connectivity_list.str();
}