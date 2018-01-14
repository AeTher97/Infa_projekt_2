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

    Factory factory =load_factory_structure("D://projekt_inf2/test.txt");

    generate_structure_report(factory,"D://projekt_inf2/structure.txt");
    TimeOffset time = TimeOffset(2);

    std::function <void(Factory&,TimeOffset)> function = [](Factory& fact, TimeOffset time){ return; 0;};

    simulate(factory,time,function);
    system("PAUSE");
    return 0;
}