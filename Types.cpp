//
// Created by Michał on 10.01.2018.
//

#include "Types.h"
#include <string>

bool ElementID::operator==(const ElementID & id_to_compare) const {
    return this->id== id_to_compare.string();
}

std::string ElementID::string() const {
    return id;
}

void ElementID::set_id(std::string new_id) {
    id = new_id;

}



int TimeOffset::get_int() const {
    return time_offset;
}



int Time::get_int() const {
    return time;
}

void Time::operator=(const Time & new_time) {
    this->time=new_time.get_int();
}

void Time::reset() {
    time=0;

}

void Time::set(int a) {
    time = a;

}

ElementID Package::get_id() {
    return id;
}

Package::Package(ElementID new_id) {
    id = new_id;
}
