//
// Created by adrja on 21.04.2018.
//

#include <set>
#include <map>
#include "WordCounter.h"

datastructures::WordCounter::WordCounter() = default;

datastructures::WordCounter::WordCounter(const std::initializer_list<datastructures::Word> &initializer_list) {

    for (const auto &element : initializer_list) {
        ++(counter_[element]);
    }
}

datastructures::Counts datastructures::WordCounter::DistinctWords() {
    return {counter_.size()};
}

datastructures::Counts datastructures::WordCounter::TotalWords() {
    size_t sum = 0;
    for (const auto &element: counter_) {
        sum += element.second.Get();
    }

    return {sum};
}

std::set<datastructures::Word> datastructures::WordCounter::Words() {
    std::set<Word> new_set;

    for (const auto &word: counter_) {
        new_set.emplace(word.first);
    }
    return new_set;
}

datastructures::Counts datastructures::WordCounter::operator[](const std::string &key) {
    try {
        return counter_.at(key);
    }
    catch (std::out_of_range) {
        return {0};
    }
}

datastructures::Counts datastructures::WordCounter::operator[](const datastructures::Word &key) {
    return counter_[key];
}
