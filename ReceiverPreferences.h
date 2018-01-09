
#ifndef PROJEKT_NA_INFORMATYKE_RECEIVER_PREFERENCES_H
#define PROJEKT_NA_INFORMATYKE_RECEIVER_PREFERENCES_H

#include <map>
#include "IPackageReceiver.h"


class ReceiverPreferences {
private:
    std::map<IPackageReceiver*,double> probabilities;
public:
    std::map<IPackageReceiver*,double> get_preferences();
    void set_preferences(std::map<IPackageReceiver*, double>);
    void add_receiver(IPackageReceiver*);
    void add_receiver_with_probability(IPackageReceiver*, double);
    void remove_receiver(IPackageReceiver*);
    IPackageReceiver* draw_receiver();
    std::pair<IPackageReceiver*,double> view();
    void print();
};


#endif //PROJEKT_NA_INFORMATYKE_RECEIVER_PREFERENCES_H
