
#include "ElementID.h"
bool ElementID::operator==(const ElementID & id_to_compare) const {
    return this->id== id_to_compare.string();
}

std::string ElementID::string() const {
    return id;
}

void ElementID::set_id(std::string new_id) {
    id = new_id;

}
