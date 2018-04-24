//
// Created by adrja on 21.04.2018.
//

#include <cstddef>
#include "Counts.h"

datastructures::Counts::Counts() {
    counts_ = 0;
}

datastructures::Counts::Counts(size_t size) {
    counts_ = size;
}

datastructures::Counts &datastructures::Counts::operator++() {
    ++counts_;
    return *this;
}

size_t datastructures::Counts::Get() const {
    return counts_;
}

bool datastructures::operator==(const datastructures::Counts &l, const datastructures::Counts &r) {
    return l.counts_ == r.counts_;
}

void datastructures::Counts::Set(size_t size) {
    counts_ = size;
}
