//
// Created by Michał on 11.12.2017.
//

#include <string>
#include <iostream>
#include "Worker.h"
#include "Types.h"
#include "PackageQueue.h"

Worker::Worker(ElementID new_id, TimeOffset new_time_offset,IPackageQueue* new_queue) {
    id = new_id;
    processing_duration = new_time_offset;
    currently_processed_package;
    queue = new_queue;
    queue_type = new_queue->get_queue_type();
    package_processing__start_time.set(0);
    type=WORKER;
}


void Worker::receive_package(Package new_package) {
    std::cout<<this->get_id().string()<<" RECEIVING package: "<<new_package.get_id().string() <<std::endl;

    queue->push(new_package);

}

void Worker::do_work(Time time) {

    std::cout<<std::endl<< this->get_id().string()<<" evaluation " <<std::endl;
    if(currently_processed_package.empty())
    {
        if(!(queue->empty())) {
            currently_processed_package.push_back(queue->pop());
            std::cout <<this->get_id().string()<<" starting to process " << this->currently_processed_package.front().get_id().string() << " at time: " <<time.get_int()<<std::endl;


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

Time Worker::get_package_processing_start_time()const {
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
}

QueueType Worker::get_queue_type() const {
    return queue_type;
}

Worker::Worker(const Worker & worker_old) {
    this->processing_duration = worker_old.get_processing_duration();
    this->id = worker_old.get_id();
    this->queue_type = worker_old.get_queue_type();
    this->package_processing__start_time = worker_old.get_package_processing_start_time();
    this->type = worker_old.get_receiver_type();
    this->currently_processed_package = worker_old.currently_processed_package;
    PackageQueue* new_queue= new PackageQueue(worker_old.get_queue_type());
    for(auto element : worker_old.view_depot())
        new_queue->push(element);
    this->queue = new_queue;

}
