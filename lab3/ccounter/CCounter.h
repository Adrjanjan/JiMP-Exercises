//
// Created by adrja on 22.03.2018.
//

#ifndef JIMP_EXERCISES_CCOUNTER_H
#define JIMP_EXERCISES_CCOUNTER_H

#include <string>
#include <memory>
#include <map>
#include <vector>

namespace ccounter {

    typedef struct c {
        std::vector<std::string> objects;
        std::map<std::string, int> instances_counter;
    } Counter;

    std::unique_ptr<Counter> Init();

    void Inc(std::string key, std::unique_ptr<Counter> *counter);

    int Counts(const std::unique_ptr<Counter> &counter, std::string key);

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter);

}
#endif //JIMP_EXERCISES_CCOUNTER_H
