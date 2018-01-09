

#ifndef PROJEKT_NA_INFORMATYKE_ELEMENT_ID_H
#define PROJEKT_NA_INFORMATYKE_ELEMENT_ID_H

#include <string>

class ElementID {
private:
    std::string id;

public:
    std::string string() const ;
    void set_id(std::string);
    bool operator ==(const ElementID&) const;
};



#endif //PROJEKT_NA_INFORMATYKE_ELEMENT_ID_H
