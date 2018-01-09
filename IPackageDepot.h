
#include <vector>
#include "Package.h"

#ifndef PROJEKT_NA_INFORMATYKE_I_PACKAGE_DEPOT_H
#define PROJEKT_NA_INFORMATYKE_I_PACKAGE_DEPOT_H

class IPackageDepot{

public:
    virtual void push(Package)=0;
    virtual bool empty()const=0;
    virtual int size()const=0;
    virtual Package view()const=0 ;

};


#endif //PROJEKT_NA_INFORMATYKE_I_PACKAGE_DEPOT_H
