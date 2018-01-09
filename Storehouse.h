
#include <string>
#include <vector>
#include "IPackageReceiver.h"
#include "IPackageDepot.h"

#ifndef PROJEKT_NA_INFORMATYKE_STOREHOUSE_H
#define PROJEKT_NA_INFORMATYKE_STOREHOUSE_H


class Storehouse : public IPackageReceiver{
private:
    std::vector<Package> packages;
    ReceiverType reciever_type;
    IPackageDepot* packageDepot;
    ElementID id;
public:
    virtual void receive_package(Package);
    virtual Package view_depot() const;
    virtual ReceiverType get_receiver_type()const;
    virtual ElementID get_id()const;
    virtual Package view()const;
    virtual void push(Package);

    Storehouse(ElementID);


};


#endif //PROJEKT_NA_INFORMATYKE_STOREHOUSE_H
