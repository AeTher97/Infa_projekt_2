//
// Created by Michał on 09.01.2018.
//
#include <vector>
#include "Types.h"

#ifndef PROJEKT_NA_INFORMATYKE_I_PACKAGE_DEPOT_H
#define PROJEKT_NA_INFORMATYKE_I_PACKAGE_DEPOT_H

class IPackageDepot{

public:
    virtual void push(Package)=0;
    virtual bool empty()const=0;
    virtual int size()const=0;
    virtual std::vector<Package> view()const=0 ;

};


#endif //PROJEKT_NA_INFORMATYKE_I_PACKAGE_DEPOT_H
