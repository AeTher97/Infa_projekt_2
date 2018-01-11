//
// Created by Michał on 11.01.2018.
//

#include "Simulation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "MyString.h"
#include "PackageQueue.h"
#include "Enums.h"
#include "PackageDepot.h"
#include <string>

Factory load_factory_structure(std::string path) {
    MyString string;
    NodeType type;
    Factory factory;
    std::ifstream file("D://projekt_inf2/test.txt");
    std::cout<<"opening file"<<std::endl;
    if(file.is_open()) {
        std::cout<<"opened file";
        while (file.good()) {
            getline(file, string);
            std::cout<<string<<std::endl;
            type=string.get_type();
            if(type == RAMP_NODE)
            {
                Ramp ramp = Ramp(string.get_id(),string.get_delivery_interval());
                factory.add_ramp(ramp);

            }
            if(type == WORKER_NODE)
            {
                PackageQueue* queue =  new PackageQueue(string.get_queue_type());
                Worker worker =   Worker(string.get_id(),string.get_processing_time(),queue);
                factory.add_worker(worker);
            }

            if(type == STORAGE_NODE)
            {
                PackageDepot * depot = new PackageDepot();
                Storehouse storehouse = Storehouse(string.get_id(),depot);
                factory.add_storehouse(storehouse);
            }
            if(type == LINK_NODE)
            {
                double p = string.get_probability();
                if(p!=0) {
                    factory.find_sender(string.get_source())->receiver_preferences.add_receiver_with_probability(
                            factory.find_receiver(string.get_destination()), p);
                }
                else
                    factory.find_sender(string.get_source())->receiver_preferences.add_receiver(factory.find_receiver(string.get_destination()));

            }
        }
    }
    file.close();
    return factory;
}

