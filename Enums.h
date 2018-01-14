//
// Created by Michał on 09.01.2018.
//

#ifndef PROJEKT_NA_INFORMATYKE_ENUMS_H
#define PROJEKT_NA_INFORMATYKE_ENUMS_H

enum ReceiverType{
    WORKER,
    STOREHOUSE
};

enum QueueType{
    LIFO,
    FIFO
};

enum NodeType{
    RAMP_NODE,
    WORKER_NODE,
    STORAGE_NODE,
    LINK_NODE,
    PACKAGE,
    EMPTY
};

enum SearchType{
    ID,
    DELIVERY_INTERVAL,
    NODE_TYPE,
    PROCESSING_TIME,
    QUEUE_TYPE,
    SOURCE,
    DESTINATION,
    PROBABILITY
};


#endif //PROJEKT_NA_INFORMATYKE_ENUMS_H
