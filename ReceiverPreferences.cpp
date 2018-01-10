//
// Created by Michał on 09.01.2018.
//

#include <time.h>
#include <iostream>
#include "ReceiverPreferences.h"

std::map<IPackageReceiver *, double> ReceiverPreferences::get_preferences() {
    return probabilities;
}

void ReceiverPreferences::set_preferences(std::map<IPackageReceiver *, double> new_preferences) {
    probabilities=new_preferences;
}

void ReceiverPreferences::add_receiver(IPackageReceiver * new_element) {
    double new_probability = 1/double(probabilities.size()+1);
    for(auto& element : probabilities)
    {
        element.second=new_probability;
    }
    probabilities.insert(std::make_pair(new_element,new_probability));
}

void ReceiverPreferences::add_receiver_with_probability(IPackageReceiver* new_element, double new_probability) {
    for(auto& element : probabilities)
    {
        element.second = (1-new_probability)*element.second;
    }
    probabilities.insert(std::make_pair(new_element,new_probability));
}

void ReceiverPreferences::remove_receiver(IPackageReceiver * to_delete) {
    auto deleted = probabilities.find(to_delete);
    double deleted_preference = deleted->second;
    probabilities.erase(deleted);
    for(auto& element : probabilities)
    {
        element.second = (element.second/(1-deleted_preference));
    }
}

IPackageReceiver *ReceiverPreferences::draw_receiver() {
    int number = probabilities.size();
    int counter =0;
    srand(time(NULL));
    int generation_result = rand() % number;
    for(auto& element : probabilities)
    {
        if(counter == generation_result)
            return element.first;
        counter++;
    }

}

void ReceiverPreferences::print() {
    for(auto element : probabilities)
        std::cout << element.first << " " << element.second<<std::endl;


}
