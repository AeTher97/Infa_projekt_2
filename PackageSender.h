
#include "ReceiverPreferences.h"
#include "Package.h"
#include <vector>

#ifndef PROJEKT_NA_INFORMATYKE_PACKAGE_SENDER_H
#define PROJEKT_NA_INFORMATYKE_PACKAGE_SENDER_H


class PackageSender {
private:

    std::vector<Package> sending_buffer;

public:
    ReceiverPreferences receiver_preferences;
    void send_package();
    void add_to_buffer(Package);
    Package view_sending_buffer();
};


#endif //PROJEKT_NA_INFORMATYKE_PACKAGE_SENDER_H
