//
// Created by Michał on 11.12.2017.
//

#include <string>
#include <iostream>
#include "Worker.h"

Worker::Worker(ElementID new_id, TimeOffset new_time_offset, IPackageQueue * new_package_queue) {
    id = new_id;
    processing_duration = new_time_offset;
    queue = new_package_queue;
queue_type = queue->get_queue_type();
}

void Worker::receive_package(Package new_package) {
    queue->push(new_package);

}

void Worker::do_work() {
    add_to_buffer(queue->pop());
    send_package();
}

ReceiverType Worker::get_receiver_type() const {
    return type;
}

Time Worker::get_package_processing_start_time() {
    Time time;
    return time;
    //#TODO
}

ElementID Worker::get_id() const {
    return id;
}

Package Worker::view_depot() const {

    //#TODO
}

std::deque<Package> Worker::view_queue() const {
    return queue->view2();
}
