//
// Created by Michał on 11.12.2017.
//
#include <string>
#include <vector>
#include "Types.h"
#include "Time.h"
#include "PackageSender.h"

#ifndef PROJEKT_NA_INFORMATYKE_RAMP_H
#define PROJEKT_NA_INFORMATYKE_RAMP_H

class Ramp : public PackageSender{

private:
    ElementID id;
    TimeOffset delivery_interval;

public:
    Ramp(ElementID,TimeOffset);
    void deliver_goods(Time);
    TimeOffset get_delivery_interval();
    ElementID get_id() const;

};



#endif //PROJEKT_NA_INFORMATYKE_RAMP_H
