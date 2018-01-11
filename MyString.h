//
// Created by Michał on 11.01.2018.
//

#ifndef PROJEKT_NA_INFORMATYKE_MYSTRING_H
#define PROJEKT_NA_INFORMATYKE_MYSTRING_H

#include <string>
#include "Enums.h"
#include "Types.h"

class MyString : public std::string{
public:
    NodeType get_type();
    ElementID get_id();
    ElementID get_destination();
    ElementID get_source();
    double get_probability();
    QueueType get_queue_type();
    int get_processing_time();
    int get_delivery_interval();

};


#endif //PROJEKT_NA_INFORMATYKE_MYSTRING_H
