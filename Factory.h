//
// Created by Michał on 11.12.2017.
//

#ifndef PROJEKT_NA_INFORMATYKE_FACTORY_H
#define PROJEKT_NA_INFORMATYKE_FACTORY_H


#include "Worker.h"
#include "Storehouse.h"
#include "Ramp.h"
#include "Types.h"
#include <list>

class Factory {
private:
    std::list<Worker> workers;
    std::list<Storehouse> storehouses;
    std::list<Ramp> ramps;

public:

    std::list<Ramp>& get_ramps();
    void add_ramp(Ramp);
    void remove_ramp(ElementID);
    Ramp* find_ramp(ElementID)  ;

    std::list<Worker>& get_workers();
    void add_worker(Worker&);
    void remove_worker(ElementID);
    Worker* find_worker(ElementID)  ;

    std::list<Storehouse>& get_storehouses();
    void add_storehouse(Storehouse);
    void remove_storehouse(ElementID);
    Storehouse* find_storehouse(ElementID)  ;
    IPackageReceiver * find_receiver(ElementID);
    PackageSender * find_sender(ElementID);

    bool isConsistent();


};


#endif //PROJEKT_NA_INFORMATYKE_FACTORY_H
