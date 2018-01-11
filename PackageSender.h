        //
// Created by Michał on 09.01.2018.
//
#include "ReceiverPreferences.h"
#include "Types.h"
#include <vector>
#include <list>

#ifndef PROJEKT_NA_INFORMATYKE_PACKAGE_SENDER_H
#define PROJEKT_NA_INFORMATYKE_PACKAGE_SENDER_H


class PackageSender {
private:



public:
    std::list<Package> sending_buffer;
    ReceiverPreferences receiver_preferences;
    void send_package();
    void add_to_buffer(Package);
    std::vector<Package> view_sending_buffer();
};


#endif //PROJEKT_NA_INFORMATYKE_PACKAGE_SENDER_H
