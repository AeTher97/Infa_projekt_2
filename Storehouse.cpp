//
// Created by Michał on 11.12.2017.
//
#include <iostream>
#include "Storehouse.h"
#include "Types.h"

ElementID Storehouse::get_id() const {
    return id;
}

Storehouse::Storehouse(ElementID new_id) {
    id =new_id;
    reciever_type = STOREHOUSE;

}

void Storehouse::receive_package(Package new_package) {
    this->push(new_package);

}

ReceiverType Storehouse::get_receiver_type() const {
    return reciever_type;
}

Package Storehouse::view() const {
    return packages.front();
}

void Storehouse::push(Package new_package) {
packages.push_back(new_package);

}

Package Storehouse::view_depot() const {
    return Package(ElementID());
}


