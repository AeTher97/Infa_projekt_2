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
    std::ifstream file(path);
    std::cout << "opening file" << std::endl;

    if (file.is_open()) {
        std::cout << "opened file";
        while (file.good()) {
            getline(file, string);
            if (string.front() != ';') {
                std::cout << string << std::endl;
                type = string.get_type();
                if (type == RAMP_NODE) {
                    ElementID id;
                    std::string worker_name = "ramp-";
                    id.set_id(worker_name + string.get_id().string());
                    Ramp ramp = Ramp(id, string.get_delivery_interval());
                    factory.add_ramp(ramp);

                }
                if (type == WORKER_NODE) {
                    PackageQueue *queue = new PackageQueue(string.get_queue_type());
                    ElementID id;
                    std::string worker_name = "worker-";
                    id.set_id(worker_name + string.get_id().string());
                    Worker worker = Worker(id, string.get_processing_time(),queue);
                    factory.add_worker(worker);
                }

                if (type == STORAGE_NODE) {
                    ElementID id;
                    std::string worker_name = "store-";
                    id.set_id(worker_name + string.get_id().string());
                    PackageDepot *depot = new PackageDepot();
                    Storehouse storehouse = Storehouse(id,depot);
                    factory.add_storehouse(storehouse);
                }
                if (type == LINK_NODE) {
                    double p = string.get_probability();
                    if (p != 0) {
                        factory.find_sender(string.get_source())->receiver_preferences.add_receiver_with_probability(
                                factory.find_receiver(string.get_destination()), p);
                    } else
                        factory.find_sender(string.get_source())->receiver_preferences.add_receiver(
                                factory.find_receiver(string.get_destination()));
                }
                if (type == PACKAGE) {
                    ElementID id;
                    id.set_id(string.get_id().string());
                    std::cout << id.string() << std::endl;
                    Package pack = Package(id);
                    factory.find_sender(string.get_destination())->add_to_buffer(pack);
                }
            }
        }
    }
    file.close();
    return factory;
}

void save_factory_structure(Factory factory, std::string path) {
    std::ofstream my_file;
    my_file.open(path);

    my_file << "; == LOADING_RAMPS ==" << "\n";
    my_file << "\n";
    for (auto element : factory.get_ramps()) {
        std::string substract = "ramp-";
        my_file << "LOADING_RAMP " << "id="
                << (element.get_id().string()).substr(substract.length(), element.get_id().string().length())
                << " delivery-interval=" << element.get_delivery_interval().get_int() << "\n";

    }
    my_file << "\n";
    my_file << "; == WORKERS ==" << "\n";
    my_file << "\n";
    for (auto element : factory.get_workers()) {
        std::string queue;
        if (element.get_queue_type() == FIFO)
            queue = "FIFO";
        else if (element.get_queue_type() == LIFO)
            queue = "LIFO";
        std::string substract = "worker-";
        my_file << "WORKER " << "id="
                << element.get_id().string().substr(substract.length(), element.get_id().string().length())
                << " processing-time=" << element.get_processing_duration().get_int() << " queue-type="
                << queue << "\n";
    }
    my_file << "\n";
    my_file << "; == STOREHOUSES ==" << "\n";
    my_file << "\n";
    for (auto element : factory.get_storehouses()) {
        std::string substract = "store-";
        my_file << "STOREHOUSE " << "id="
                << element.get_id().string().substr(substract.length(), element.get_id().string().length()) << "\n";
    }
    my_file << "\n";
    my_file << "; == LINKS ==" << "\n";
    my_file << "\n";
    for (auto element : factory.get_ramps()) {
        for (auto inner_element : element.receiver_preferences.view())
            my_file << "LINK " << "src=" << element.get_id().string() << " dest="
                    << inner_element.first->get_id().string() << " p=" << inner_element.second << "\n";
        my_file << "\n";
    }

    for (auto element : factory.get_workers()) {
        for (auto inner_element : element.receiver_preferences.view())
            my_file << "LINK " << "src=" << element.get_id().string() << " dest="
                    << inner_element.first->get_id().string() << " p=" << inner_element.second << "\n";

    }

    my_file << "; == PACKAGES ==" << "\n";
    my_file << "\n";
    for (auto element : factory.get_ramps()) {
        for (auto inner_element : element.view_sending_buffer())
            my_file << "PACKAGE" << " id=" << inner_element.get_id().string() << " dest=" << element.get_id().string();

        my_file << "\n";
    }

    my_file.close();


}


void generate_structure_report(Factory factory,std::string path){
    std::ofstream my_file;
    my_file.open(path);

    my_file << " == LOADING_RAMPS ==" << "\n";
    my_file << "\n";
    for (auto element : factory.get_ramps()) {
        std::string substract = "ramp-";
        my_file << "LOADING_RAMP #" << (element.get_id().string()).substr(substract.length(), element.get_id().string().length()) << "\n"
                << "  Delivery interval: " << element.get_delivery_interval().get_int() << "\n";
        my_file << "  Receivers: " << "\n";
        for(auto inner_element : element.receiver_preferences.view())
        {
            my_file << "    ";
            my_file << inner_element.first->get_id().string().replace(inner_element.first->get_id().string().find("-"),1," #");
            my_file << " (p = " << inner_element.second << ")" << "\n";
        }
        my_file << "\n";
    }

    my_file << " == WORKERS ==" << "\n";
    my_file << "\n";
    for (auto element : factory.get_workers()) {
        std::string queue;
        if (element.get_queue_type() == FIFO)
            queue = "FIFO";
        else if (element.get_queue_type() == LIFO)
            queue = "LIFO";
        std::string substract = "worker-";
        my_file << "WORKER #" << element.get_id().string().substr(substract.length(), element.get_id().string().length())
                << "\n"<<"  Processing time: " << element.get_processing_duration().get_int() << "\n" <<  "Queue type: "
                << queue << "\n";
        for(auto inner_element : element.receiver_preferences.view())
        {
            my_file << "    ";
            my_file << inner_element.first->get_id().string().replace(inner_element.first->get_id().string().find("-"),1," #");
            my_file << " (p = " << inner_element.second << ")" << "\n";
        }
    }
    my_file << "\n";
    my_file << " == STOREHOUSES ==" << "\n";
    my_file << "\n";

    for (auto element : factory.get_storehouses()){
        std::string subtract ="store-";
        my_file << "STOREHOUSE #" << element.get_id().string().substr(subtract.length(),element.get_id().string().length());
        my_file << "\n";
    }

    my_file.close();

}


void generate_simulation_turn_report(Factory factory,std::string path,Time time)
{
    std::ofstream my_file;
    my_file.open(path);

    my_file << " == WORKERS ==" << "\n";
    my_file << "\n";
    for (auto element : factory.get_workers()) {
        std::string substract = "worker-";
        my_file << "WORKER #" << element.get_id().string().substr(substract.length(), element.get_id().string().length()) << "\n";
        my_file <<"  Queue: ";
        int viewed = 0;
        for(auto inner_element : element.view_depot())
        {
            if(viewed==0)
                my_file <<  "#" << inner_element.get_id().string() << " (pt = " << time.get_int() - element.get_package_processing_start_time().get_int() <<" ) ";
            else
                my_file <<  ", #" << inner_element.get_id().string();
            viewed=1;
        }
        my_file << "\n";
    }
    my_file << "\n";
    my_file << " == STOREHOUSES ==" << "\n";
    my_file << "\n";

    for (auto element : factory.get_storehouses()){
        std::string subtract ="store-";
        my_file << "STOREHOUSE #" << element.get_id().string().substr(subtract.length(),element.get_id().string().length()) << "\n";
        my_file <<"  Queue: ";
        int viewed = 0;
        for(auto inner_element : element.view_depot())
        {
            if(viewed==0)
                my_file <<  "#" << inner_element.get_id().string() ;
            else
                my_file <<  ", #" << inner_element.get_id().string();
            viewed=1;
        }
        my_file << "\n";
    }

    my_file.close();
}


void simulate(Factory,TimeOffset,std::function<void(Factory&,TimeOffset)>){

}
