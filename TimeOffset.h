

#ifndef PROJEKT_NA_INFORMATYKE_TIME_OFFSET_H
#define PROJEKT_NA_INFORMATYKE_TIME_OFFSET_H

class TimeOffset{
private:
    int time_offset;
public:
    TimeOffset(int time){time_offset=time;};
    TimeOffset(){time_offset=5;};
    int get_int() const ;
};

#endif //PROJEKT_NA_INFORMATYKE_TIME_OFFSET_H
