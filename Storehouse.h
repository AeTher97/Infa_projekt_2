//
// Created by Michał on 11.12.2017.
//

#include <string>
#include <vector>
#include "IPackageReceiver.h"
#include "IPackageDepot.h"

#ifndef PROJEKT_NA_INFORMATYKE_STOREHOUSE_H
#define PROJEKT_NA_INFORMATYKE_STOREHOUSE_H
#include <list>


class Storehouse : public IPackageReceiver{
private:
    ReceiverType receiver_type;
    IPackageDepot* packageDepot;
    ElementID id;
public:
    virtual void receive_package(Package);
    virtual std::vector<Package> view_depot() const;
    virtual ReceiverType get_receiver_type()const;
    virtual ElementID get_id()const;
    Storehouse(ElementID,IPackageDepot *);
    ~Storehouse();


};


#endif //PROJEKT_NA_INFORMATYKE_STOREHOUSE_H
