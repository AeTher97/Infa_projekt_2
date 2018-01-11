//
// Created by Michał on 11.12.2017.
//
#include <iostream>
#include "Storehouse.h"
#include "Types.h"

ElementID Storehouse::get_id() const {
    return id;
}

Storehouse::Storehouse(ElementID new_id,IPackageDepot* depot) {
    id =new_id;
    receiver_type = STOREHOUSE;
    packageDepot = depot;

}

void Storehouse::receive_package(Package new_package) {
    std::cout<<this->get_id().string()<<" RECEIVED package: " << new_package.get_id().string() <<std::endl;
    packageDepot->push(new_package);

}

ReceiverType Storehouse::get_receiver_type() const {
    return receiver_type;
}


std::vector<Package> Storehouse::view_depot() const {
    std::vector<Package> list;
    for(auto element : packageDepot->view())
        list.push_back(element);
    return list;
}

Storehouse::~Storehouse() {
    delete(packageDepot);

}


