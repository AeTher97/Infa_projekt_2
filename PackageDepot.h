//
// Created by Michał on 10.01.2018.
//

#ifndef PROJEKT_NA_INFORMATYKE_PACKAGEDEPOT_H
#define PROJEKT_NA_INFORMATYKE_PACKAGEDEPOT_H

#include <list>
#include "IPackageDepot.h"

class PackageDepot : public IPackageDepot {
private:
    std::list<Package> storage;
public:
    virtual void push(Package);
    virtual bool empty()const;
    virtual int size()const;
    virtual std::vector<Package> view()const;
};


#endif //PROJEKT_NA_INFORMATYKE_PACKAGEDEPOT_H
