//
// Created by Michał on 09.01.2018.
//

#include <iostream>
#include "PackageSender.h"

void PackageSender::send_package() {
    if(!sending_buffer.empty()) {
        std::cout<< "buffer is not empty... SENDING " <<std::endl;
        receiver_preferences.draw_receiver()->receive_package(sending_buffer.front());
        sending_buffer.erase(sending_buffer.begin());
    }
}

void PackageSender::add_to_buffer(Package new_package) {
    sending_buffer.push_back(new_package);
}

std::vector<Package> PackageSender::view_sending_buffer() {
    std::vector<Package> list;
    for(auto element : sending_buffer)
        list.push_back(element);
    return list;

}
