//
// Created by Michał on 11.12.2017.
//
#include <iostream>
#include "Storehouse.h"
#include "Types.h"
#include "PackageDepot.h"

ElementID Storehouse::get_id() const {
    return id;
}

Storehouse::Storehouse(ElementID new_id,IPackageDepot* new_depot) {
    id =new_id;
    packageDepot = new_depot;
    receiver_type = STOREHOUSE;

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

Storehouse::Storehouse(const Storehouse& storehouse_old) {
    id = storehouse_old.get_id();
    receiver_type = storehouse_old.get_receiver_type();
    PackageDepot* new_depot = new PackageDepot();
    for(auto element : storehouse_old.view_depot())
    {
        new_depot->push(element);
    }
    packageDepot = new_depot;

}

void Storehouse::add_package_depot(IPackageDepot * new_depot) {
    packageDepot = new_depot;

}


