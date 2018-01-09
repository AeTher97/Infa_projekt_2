
#include "Time.h"


int Time::get_int() const {
    return time;
}

void Time::operator=(const Time & new_time) {
    this->time=new_time.get_int();
}