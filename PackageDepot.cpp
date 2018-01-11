//
// Created by Michał on 10.01.2018.
//

#include "PackageDepot.h"

void PackageDepot::push(Package new_package) {
    storage.push_back(new_package);

}

bool PackageDepot::empty() const {
    return storage.empty();
}

int PackageDepot::size() const {
    return storage.size();
}

std::vector<Package> PackageDepot::view() const {
    std::vector<Package> list;
    for(auto element : storage)
        list.push_back(element);
    return  list;
}




