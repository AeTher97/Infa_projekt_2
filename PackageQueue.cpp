//
// Created by Michał on 09.01.2018.
//

#include <iostream>
#include "PackageQueue.h"

PackageQueue::PackageQueue(QueueType type) {
    queue_type=type;
}



Package PackageQueue::pop() {
    return _pop_function();
}

void PackageQueue::push(Package new_package) {
    deque.push_back(new_package);

}

bool PackageQueue::empty() const {
    return deque.empty();
}

int PackageQueue::size() const {
    return deque.size();
}

QueueType PackageQueue::get_queue_type() {
    return queue_type;
}

std::vector<Package> PackageQueue::view() const {
    std::vector<Package> list;
    for(auto element : deque)
        list.push_back(element);
    return list;
}

PackageQueue::~PackageQueue() {
    std::cout << "gone" <<std::endl;

}
