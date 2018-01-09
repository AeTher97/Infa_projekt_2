#include <iostream>
#include "Worker.h"
#include "PackageQueue.h"
#include "Enums.h"
#include "Storehouse.h"
#include "Factory.h"
int main() {
    TimeOffset time(2);
    ElementID id;
    ElementID id2;
    ElementID id3;
    id.set_id("sio");
    id3.set_id("zol");
    id2.set_id("lol");
    PackageQueue queue(LIFO);

    Storehouse storehouse(id3);
    Package aPackage(id2);
    Worker worker(id,time,&queue);                 //jakies tam przykladowe linijki
    worker.receiver_preferences.add_receiver(&storehouse);
    worker.receive_package(aPackage);
    worker.do_work();
    worker.receive_package(aPackage);
    for(auto item : worker.view_queue())
        std::cout<< item.get_id().string()<<std::endl;

    Factory factory;
    factory.add_worker(worker);
    factory.add_storehouse(storehouse);
    std::cout<< factory.get_workers().front().get_id().string();
    factory.remove_worker(id);

    std::cout<<std::endl<<factory.get_workers().empty();
}