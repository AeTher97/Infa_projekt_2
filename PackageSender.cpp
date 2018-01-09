
#include "PackageSender.h"

void PackageSender::send_package() {
    receiver_preferences.draw_receiver()->receive_package(sending_buffer.front());
    sending_buffer.erase(sending_buffer.begin());
}

void PackageSender::add_to_buffer(Package new_package) {
    sending_buffer.push_back(new_package);
}
