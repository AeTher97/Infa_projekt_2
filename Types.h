//
// Created by Michał on 10.01.2018.
//
#include <string>
#include "Enums.h"
#ifndef TESTING_TYPES_H
#define TESTING_TYPES_H

class ElementID {
private:
    std::string id;

public:
    std::string string() const ;
    void set_id(std::string);
    bool operator ==(const ElementID&) const;
};


class Package {
private:
    ElementID id;
public:
    Package(){ ElementID id_new; id_new.set_id("null");id=id_new;};
    Package(ElementID);
    ElementID get_id();
};

class Time{
private:
    int time;
public:
    Time(){};
    int get_int() const ;
    void reset();
    void set(int a);
    void operator = (const Time&);
};

class TimeOffset{
private:
    int time_offset;
public:
    TimeOffset(int time){time_offset=time;};
    TimeOffset(){time_offset=0;};
    int get_int() const ;
};



#endif //TESTING_TYPES_H
