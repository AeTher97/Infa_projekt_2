//
// Created by Michał on 11.12.2017.
//

#include <iostream>
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

Ramp* Factory::find_ramp(ElementID id)  {
    auto iterator = std::find_if(ramps.begin(),ramps.end(),[id](Ramp const& item){return item.get_id().string()==id.string();});
    if(iterator==ramps.end())
        if(ramps.back().get_id()==id)
            return &(*iterator);
        else
            return nullptr;
    return &(*iterator);

}


std::list<Worker> &Factory::get_workers() {
    return workers;
}

void Factory::add_worker(Worker& new_worker) {
    workers.push_back(new_worker);
}

void Factory::remove_worker(ElementID id_to_delete) {
    auto iterator = std::find_if(workers.begin(),workers.end(),[id_to_delete](Worker const& item){return
            item.get_id().string()==
                                                                                                         id_to_delete.string();});
    workers.erase(iterator);
}

Worker *Factory::find_worker(ElementID id) {
    auto iterator = std::find_if(workers.begin(),workers.end(),[id](Worker const& item){return
            item.get_id().string()==
            id.string();});
    if(iterator==workers.end())
        if(workers.back().get_id()==id)
            return &(*iterator);
        else
            return nullptr;
    return &(*iterator);
}



std::list<Storehouse> &Factory::get_storehouses() {
    return storehouses;
}

void Factory::add_storehouse(Storehouse new_storehouse) {
    storehouses.push_back(new_storehouse);
}

void Factory::remove_storehouse(ElementID id_to_delete) {
    auto iterator = std::find_if(storehouses.begin(),storehouses.end(),[id_to_delete](Storehouse const& item){return item.get_id().string()==id_to_delete.string();});
    storehouses.erase(iterator);
}

Storehouse *Factory::find_storehouse(ElementID id)  {
    auto iterator = std::find_if(storehouses.begin(),storehouses.end(),[id](Storehouse const& item){return
            item.get_id().string()==
            id.string();});
    if(iterator==storehouses.end())
        if(storehouses.back().get_id()==id)
            return &(*iterator);
        else
            return nullptr;
    return &(*iterator);

}

bool Factory::isConsistent() {
 // #TODO
}

IPackageReceiver *Factory::find_receiver(ElementID id) {
    if(find_worker(id)!= nullptr) {
        return find_worker(id);
    }
    if(find_storehouse(id)!= nullptr)
        return find_storehouse(id);
    return nullptr;
}

PackageSender * Factory::find_sender(ElementID id)
{
    if(find_worker(id)!= nullptr) {
        return find_worker(id);
    }
    if(find_ramp(id)!= nullptr)
        return find_ramp(id);
    return nullptr;
}







