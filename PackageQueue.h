//
// Created by Michał on 09.01.2018.
//

#ifndef PROJEKT_NA_INFORMATYKE_PACKAGEQUEUE_H
#define PROJEKT_NA_INFORMATYKE_PACKAGEQUEUE_H

#include <deque>
#include <functional>
#include <vector>
#include "Types.h"
#include "Enums.h"
#include "IPackageQueue.h"

class PackageQueue : public IPackageQueue {
private:
    QueueType queue_type;
    std::deque<Package> deque;
    std::function<Package()> _pop_function = [this](){if(queue_type==LIFO) {
        Package last = deque.back();
        deque.pop_back();
        return last;
    }
    if(queue_type==FIFO) {
        Package first = deque.front();
        deque.pop_front();
        return  first;
    }};
public:
    PackageQueue(QueueType);
    virtual void push(Package);
    virtual bool empty()const;
    virtual int size()const;
    virtual std::vector<Package> view()const ;
    virtual Package pop();
    virtual QueueType get_queue_type();


};


#endif //PROJEKT_NA_INFORMATYKE_PACKAGEQUEUE_H
