

#ifndef PROJEKT_NA_INFORMATYKE_FACTORY_H
#define PROJEKT_NA_INFORMATYKE_FACTORY_H


#include "Worker.h"
#include "Storehouse.h"
#include "Ramp.h"
#include "ElementID.h"

class Factory {
private:
    std::vector<Worker> workers;
    std::vector<Storehouse> storehouses;
    std::vector<Ramp> ramps;

public:

    std::vector<Ramp>& get_ramps();
    void add_ramp(Ramp);
    void remove_ramp(ElementID);

    std::vector<Worker>& get_workers();
    void add_worker(Worker);
    void remove_worker(ElementID);

    std::vector<Storehouse>& get_storehouses();
    void add_storehouse(Storehouse);
    void remove_storehouse(ElementID);

    bool isConsistent();


};


#endif //PROJEKT_NA_INFORMATYKE_FACTORY_H
