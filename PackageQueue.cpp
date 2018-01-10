//
// Created by Michał on 09.01.2018.
//

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

Package PackageQueue::view() const {
    return deque.front();
}

std::deque<Package> PackageQueue::view2() const {
    return deque;
}