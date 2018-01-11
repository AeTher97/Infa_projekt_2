//
// Created by Michał on 11.01.2018.
//

#ifndef PROJEKT_NA_INFORMATYKE_SIMULATION_H
#define PROJEKT_NA_INFORMATYKE_SIMULATION_H

#include "Factory.h"


Factory load_factory_structure(std::string);

void save_factory_structure(Factory&,std::ostream&);

void generate_structure_report(Factory,std::ostream&);

void generate_simulation_turn_report(Factory,std::ostream&,Time);


#endif //PROJEKT_NA_INFORMATYKE_SIMULATION_H
