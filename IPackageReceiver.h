//
// Created by Michał on 09.01.2018.
//

#ifndef PROJEKT_NA_INFORMATYKE_IPACKAGERECEIVER_H
#define PROJEKT_NA_INFORMATYKE_IPACKAGERECEIVER_H

#include "Enums.h"
#include "Types.h"

class IPackageReceiver{
public:
    virtual void receive_package(Package) =0;
    virtual Package view_depot() const = 0;
    virtual ReceiverType get_receiver_type()const =0;
    virtual ElementID get_id() const=0;
};

#endif //PROJEKT_NA_INFORMATYKE_IPACKAGERECEIVER_H
