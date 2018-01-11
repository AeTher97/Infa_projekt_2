//
// Created by Michał on 11.12.2017.
//

#include <string>
#include <iostream>
#include "Worker.h"
#include "Types.h"

Worker::Worker(ElementID new_id, TimeOffset new_time_offset, IPackageQueue * new_package_queue) {
    id = new_id;
    processing_duration = new_time_offset;
    queue = new_package_queue;
    queue_type = queue->get_queue_type();
    currently_processed_package;
    package_processing__start_time.set(0);
    type=WORKER;
}


void Worker::receive_package(Package new_package) {
    std::cout<<"RECEIVING package: "<<new_package.get_id().string() <<std::endl;

    queue->push(new_package);


}

void Worker::do_work(Time time) {

    std::cout<<std::endl<< this->get_id().string()<<" evaluation " <<std::endl;
    std::cout <<(!currently_processed_package.empty())<<" " <<this->package_processing__start_time.get_int()<<" "<<this->get_processing_duration().get_int()<<" "<<time.get_int() <<std::endl;
    if(currently_processed_package.empty())
    {
        if(!(queue->empty())) {
            currently_processed_package.push_back(queue->pop());
            std::cout <<this->get_id().string()<<" starting to process " <<time.get_int()<<std::endl;


            this->package_processing__start_time.set(time.get_int());

        } else
            std::cout<< "worker not working queue empty " <<std::endl;
    }

    if(!(currently_processed_package.empty()) && this->package_processing__start_time.get_int()+this->get_processing_duration().get_int()==time.get_int()) {
        add_to_buffer(currently_processed_package.front());
        currently_processed_package.erase(currently_processed_package.begin());
        std::cout << "FINISHED, sending package " << sending_buffer.front().get_id().string()<<std::endl;
        send_package();
    } else if(!(currently_processed_package.empty()))
        std::cout<<"WORKING "<<std::endl;
    return;
}

ReceiverType Worker::get_receiver_type() const {
    return type;
}

Time Worker::get_package_processing_start_time() {
    return package_processing__start_time;
}

ElementID Worker::get_id() const {
    return id;
}

TimeOffset Worker::get_processing_duration() const {
    return processing_duration;
}

std::vector<Package> Worker::view_depot() const {
    std::vector<Package> list;
    for(auto element : queue->view())
        list.push_back(element);
    return list;
}

QueueType Worker::typ() {
    return queue_type;
}

Worker::~Worker() {
delete(queue);
    std::cout <<"chuj wie dlaczego ale sie niszczy"<<std::endl;

}

void Worker::set_package_processing_start_time(int a) {
    package_processing__start_time.set(a);

}
