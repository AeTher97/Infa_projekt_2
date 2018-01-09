
#include <vector>


#include "ElementID.h"
#include "TimeOffset.h"
#include "Time.h"
#include "IPackageQueue.h"
#include "IPackageReceiver.h"
#include "PackageSender.h"

#ifndef PROJEKT_NA_INFORMATYKE_WORKER_H
#define PROJEKT_NA_INFORMATYKE_WORKER_H

class Worker : public IPackageReceiver, public PackageSender{
private:
    ElementID id;
    QueueType queue_type;
    TimeOffset processing_duration;
    Time package_processing__start_time;
    IPackageQueue* queue;
    std::vector<Package> currently_processed_package;
    ReceiverType type;
public:
    Worker(ElementID,TimeOffset,IPackageQueue*);
    virtual void receive_package(Package);
    void do_work();
    TimeOffset get_processing_duration()const;
    Time get_package_processing_start_time();
    virtual ReceiverType get_receiver_type()const ;
    virtual ElementID get_id()const;
    std::deque<Package> view_queue()const ;
    virtual Package view_depot() const ;



};


#endif //PROJEKT_NA_INFORMATYKE_WORKER_H
