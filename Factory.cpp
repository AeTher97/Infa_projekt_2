//
// Created by Michał on 11.12.2017.
//

#include "Factory.h"
#include "algorithm"

std::list<Ramp> &Factory::get_ramps() {
    return ramps;
}

void Factory::add_ramp(Ramp new_ramp) {
    ramps.push_back(new_ramp);
}

void Factory::remove_ramp(ElementID id_to_delete) {
    auto iterator = std::find_if(ramps.begin(),ramps.end(),[id_to_delete](Ramp const& item){return item.get_id()==id_to_delete;});
    ramps.erase(iterator);
}


std::list<Worker> &Factory::get_workers() {
    return workers;
}

void Factory::add_worker(Worker new_worker) {
    workers.push_back(new_worker);
}

void Factory::remove_worker(ElementID id_to_delete) {
    auto iterator = std::find_if(workers.begin(),workers.end(),[id_to_delete](Worker const& item){return item.get_id().get_id()==id_to_delete.get_id();});
    workers.erase(iterator);
}



std::list<Storehouse> &Factory::get_storehouses() {
    return storehouses;
}

void Factory::add_storehouse(Storehouse new_storehouse) {
    storehouses.push_back(new_storehouse);
}

void Factory::remove_storehouse(ElementID id_to_delete) {
    auto iterator = std::find_if(storehouses.begin(),storehouses.end(),[id_to_delete](Storehouse const& item){return item.get_id()==id_to_delete;});
    storehouses.erase(iterator);
}

bool Factory::isConsistent() {
 // #TODO
}


