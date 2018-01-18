#include <iostream>
#include "Worker.h"
#include "PackageQueue.h"
#include "Enums.h"
#include "Storehouse.h"
#include "Factory.h"
#include "Types.h"
#include "Simulation.h"
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <unistd.h>

/*int main() {
    TimeOffset time(2);
    ElementID id;
    ElementID id2;
    ElementID id3;
    id.set_id("sio");
    id3.set_id("zol");
    id2.set_id("lol");
    PackageQueue queue(LIFO);
    Time time_global = Time(0);

    Storehouse storehouse(id3);
    Package aPackage(id2);
    Worker worker(id,time,&queue);
    worker.receiver_preferences.add_receiver(&storehouse);
    worker.receiver_preferences.add_receiver(&worker);
    worker.receive_package(aPackage);
    worker.do_work(time_global);
    worker.receive_package(aPackage);


    Factory factory;
    factory.add_worker(worker);
    factory.add_storehouse(storehouse);
    factory.remove_worker(id);


    for(auto element : worker.receiver_preferences.view())
    {
        std::cout<<element.first->get_id().string()<<" "<<element.second<<std::endl;
    }
}

*/
int main(){
    srand(unsigned(time(NULL)));
    Factory factory =load_factory_structure("D://projekt_inf2/test.txt");

    Time time;
    time.set(1);

    generate_structure_report(factory,"D://projekt_inf2/structure.txt");



    save_factory_structure(factory,"D://projekt_inf2/save.txt");
    std::cout<<std::endl<<"--- SIMULATION START ---"<<std::endl;
    for(int i =0;i<18;i++) {
        std::cout << std::endl << " --TURN " << time.get_int()<<" --" << std::endl;
        for (Ramp& element : factory.get_ramps()) {
            element.deliver_goods(time);

        }
        for (Worker& element : factory.get_workers()) {
            element.do_work(time);
        }

        if(time.get_int()==18)
            generate_simulation_turn_report(factory,"D://projekt_inf2/turn.txt",time);

        time.set(time.get_int()+1);
        sleep(1);
    }


    if(!factory.get_storehouses().front().view_depot().empty())
    for(auto element : factory.get_storehouses().front().view_depot())
        std::cout<<element.get_id().string()<<std::endl;


    std::cout<<std::endl<<"--- SIMULATION END ---"<<std::endl;
    system("PAUSE");
    return 0;
}