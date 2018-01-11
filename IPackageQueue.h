//
// Created by Michał on 09.01.2018.
//

#ifndef PROJEKT_NA_INFORMATYKE_IPACKAGEQUEUE_H
#define PROJEKT_NA_INFORMATYKE_IPACKAGEQUEUE_H

#include <deque>
#include "IPackageDepot.h"
#include "Enums.h"

class IPackageQueue : public IPackageDepot{
public:
    virtual Package pop()=0;
    virtual QueueType get_queue_type()=0;
};
#endif //PROJEKT_NA_INFORMATYKE_IPACKAGEQUEUE_H
