
#include "Package.h"

ElementID Package::get_id() {
    return id;
}

Package::Package(ElementID new_id) {
    id = new_id;
}
