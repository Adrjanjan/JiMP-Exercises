//
// Created by adrja on 22.03.2018.
//

#include "CCounter.h"


namespace ccounter {

    std::unique_ptr<Counter> Init() {
        std::unique_ptr<Counter> counter_structure(new Counter);
        counter_structure->objects = {};
        counter_structure->instances_counter = {};
        return std::move(counter_structure);
    }

    void Inc(std::string key, std::unique_ptr<Counter> *counter) {

        (*counter)->objects.push_back(key);

        auto it = (*counter)->instances_counter.find(key);
        if (it != (*counter)->instances_counter.end()) {
            ++(it->second);
        } else {
            (*counter)->instances_counter.emplace(key, 1);
        }
    }

    int Counts(const std::unique_ptr<Counter> &counter, std::string key) {

        auto it = counter->instances_counter.find(key);
        if (it != counter->instances_counter.end()) {
            return it->second;
        } else {
            return 0;
        }

    }

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter) {

        auto it = (*counter)->instances_counter.find(key);
        if (it != (*counter)->instances_counter.end()) {
            it->second = value;
        } else {
            (*counter)->instances_counter.emplace(key, 0);
        }
    }

}
