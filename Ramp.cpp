//
// Created by Michał on 11.12.2017.
//

#include <iostream>
#include "Ramp.h"
#include "Types.h"


ElementID Ramp::get_id() const {
    return id;
}


void Ramp::deliver_goods(Time time) {
    std::cout<<std::endl<<this->get_id().string()<<" ramp evalutaion"<<std::endl;
    if(time.get_int() % delivery_interval.get_int()==0)
        send_package();
}

Ramp::Ramp(ElementID new_id, TimeOffset new_time_offset) {
    id = new_id;
    delivery_interval = new_time_offset;
}

TimeOffset Ramp::get_delivery_interval() {
    return delivery_interval;
}
