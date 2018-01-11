//
// Created by Michał on 11.01.2018.
//

#include <iostream>
#include "MyString.h"


NodeType MyString::get_type() {
    if(this->find("LOADING_RAMP")!=std::string::npos)
        return RAMP_NODE;
    if(this->find("WORKER")!=std::string::npos)
        return WORKER_NODE;
    if(this->find("STOREHOUSE")!=std::string::npos)
        return STORAGE_NODE;
    if(this->find("LINK")!=std::string::npos)
        return LINK_NODE;
    return EMPTY;
}

ElementID MyString::get_id() {
    std::string string ="id=";
    unsigned first = this->find(string)+string.length();
    unsigned last;
    if(this->find_first_of(" ",first)!=std::string::npos)
        last = this->find_first_of(" ",first);
    else
        last = this->length();
    std::string id = this->substr(first,last-first);
    ElementID new_id;
    new_id.set_id(id);
    return new_id;
}

ElementID MyString::get_destination() {
    std::string string = "dest=";
    unsigned first = this->find(string)+string.length();
    unsigned last = this->find_first_of(" ",first);
    std::string destination = this->substr(first,last-first);
    ElementID id;
    id.set_id(destination);

    return id;
}

ElementID MyString::get_source() {
    std::string string = "src=";
    unsigned first = this->find(string)+string.length();
    unsigned last = this->find_first_of(" ",first);
    std::string source = this->substr(first,last-first);
    ElementID id;
    id.set_id(source);

    return id;
}

double MyString::get_probability() {
    std::string string = "p=";
    unsigned first = this->find(string)+string.length();
    if(first == std::string::npos)
        return 0;
    unsigned last;
    if(this->find_first_of(" ",first)!=std::string::npos)
        last = this->find_first_of(" ",first);
    else
        last = this->length();
    double probability = std::stod(this->substr(first,last-first));
    return probability;
}

QueueType MyString::get_queue_type() {
    if(this->find("LIFO")!=std::string::npos)
        return LIFO;
    if(this->find("FIFO")!=std::string::npos)
        return FIFO;
}

int MyString::get_processing_time() {
    std::string string = "processing-time=";
    unsigned first = this->find(string)+string.length();
    unsigned last;
    if(this->find_first_of(" ",first)!=std::string::npos)
        last = this->find_first_of(" ",first);
    else
        last = this->length();
    int processing_time = std::stoi(this->substr(first,last-first));
    return processing_time;
}

int MyString::get_delivery_interval() {
    std::string string ="delivery-interval=";
    unsigned first = this->find(string)+string.length();
    unsigned last;
    if(this->find_first_of(" ",first)!=std::string::npos)
        last = this->find_first_of(" ",first);
    else
        last = this->length();
    int processing_time = std::stoi(this->substr(first,last-first));

    return processing_time;
}
