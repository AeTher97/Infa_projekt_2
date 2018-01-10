//
// Created by Michał on 10.01.2018.
//
#include <string>

#ifndef TESTING_TYPES_H
#define TESTING_TYPES_H

class ElementID {
private:
    std::string id;

public:
    std::string get_id() const ;
    void set_id(std::string);
    bool operator ==(const ElementID&) const;
};


class Package {
private:
    ElementID id;
public:
    Package(ElementID);
    ElementID get_id();
};

class Time{
private:
    int time;
public:
    int get_int() const ;
    void operator = (const Time&);
};

class TimeOffset{
private:
    int time_offset;
public:
    TimeOffset(int time){time_offset=time;};
    TimeOffset(){time_offset=5;};
    int get_int() const ;
};


#endif //TESTING_TYPES_H
