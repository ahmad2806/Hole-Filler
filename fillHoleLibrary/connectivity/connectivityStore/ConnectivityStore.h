//
// Created by ahmad on 4/20/19.
//

#ifndef FILL_HOLE_CONNECTIVITYSTORE_H
#define FILL_HOLE_CONNECTIVITYSTORE_H


#include "../IPixelConnectivity.h"
#include "../../../exceptions/ExceptionValidator.h"

class ConnectivityStore {

public:
    inline void addConnectivity(IPixelConnectivity_ptr);

    std::string getRegisteredConnectivityList() const;

    inline IPixelConnectivity_ptr getConnectivity(const std::string &s) const;

    inline IPixelConnectivity_ptr getConnectivity(const int &i) const;

private:
    std::vector<IPixelConnectivity_ptr> m_connectivity_list;
};

void ConnectivityStore::addConnectivity(IPixelConnectivity_ptr connectivity) {
    m_connectivity_list.push_back(connectivity);
}

IPixelConnectivity_ptr ConnectivityStore::getConnectivity(const std::string &s) const {
    unsigned i;
    for (i = 0; i < m_connectivity_list.size(); ++i) {
        if (m_connectivity_list[i]->getName() != s) continue;
        return m_connectivity_list[i];
    }
    ExceptionValidator::connectivityNotFound();
    return m_connectivity_list[i];
}

IPixelConnectivity_ptr ConnectivityStore::getConnectivity(const int &i) const {
    return m_connectivity_list[i];
}


#endif //FILL_HOLE_CONNECTIVITYSTORE_H
