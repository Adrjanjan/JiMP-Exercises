//
// Created by adrja on 27.04.2018.
//

#include "Iterable.h"

////--Iterable----------------------------------------------------------------------------------------------------////
utility::IterableIteratorWrapper utility::Iterable::cbegin() const {
    return IterableIteratorWrapper(ConstBegin());
}

utility::IterableIteratorWrapper utility::Iterable::cend() const {
    return IterableIteratorWrapper(ConstEnd());;
}

utility::IterableIteratorWrapper utility::Iterable::begin() const {
    return cbegin();
}

utility::IterableIteratorWrapper utility::Iterable::end() const {
    return cend();
}

////--Enumerate-------------------------------------------------------------------------------------------------////
std::unique_ptr<utility::IterableIterator> utility::Enumerate::ConstBegin() const {
    return std::make_unique<EnumerateIterator>(vectors_.first.cbegin(), vectors_.second.begin());
}

std::unique_ptr<utility::IterableIterator> utility::Enumerate::ConstEnd() const {
    return std::make_unique<EnumerateIterator>(vectors_.first.cend(), vectors_.second.cend());
}

utility::Enumerate::Enumerate(const std::vector<std::string> &vs) {
    std::vector<int> temp;

    for (int i = 1; i - 1 < vs.size(); ++i) {
        temp.emplace_back(i);
    }
    vectors_ = std::make_pair(temp, vs);
};

////--Product---------------------------------------------------------------------------------------------------////
utility::Product::Product(const std::vector<int> &vi, const std::vector<std::string> &vs) {

    std::vector<int> temp_i;
    std::vector<std::string> temp_s;

    for (auto i : vi) {
        for (auto j : vs) {
            temp_i.emplace_back(i);
            temp_s.emplace_back(j);
        }
    }
    vectors_ = std::make_pair(temp_i, temp_s);
}

std::unique_ptr<utility::IterableIterator> utility::Product::ConstBegin() const {
    return std::make_unique<ProductIterator>(vectors_.first.cbegin(), vectors_.second.begin());
}

std::unique_ptr<utility::IterableIterator> utility::Product::ConstEnd() const {
    return std::make_unique<ProductIterator>(vectors_.first.cend(), vectors_.second.cend());
}

////--Zipper----------------------------------------------------------------------------------------------------////
utility::Zipper::Zipper(const std::vector<int> &vi, const std::vector<std::string> &vs) {

    std::vector<int> temp_i{vi};
    std::vector<std::string> temp_s{vs};

    if (temp_i.size() == temp_s.size()) vectors_ = std::make_pair(temp_i, temp_s);
    while (temp_s.size() > temp_i.size()) temp_i.emplace_back(temp_i.back());
    while (temp_s.size() < temp_i.size()) temp_s.emplace_back(temp_s.back());

    vectors_ = std::make_pair(temp_i, temp_s);
}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstBegin() const {
    return std::make_unique<ZipperIterator>(vectors_.first.cbegin(), vectors_.second.begin());
}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstEnd() const {
    return std::make_unique<ZipperIterator>(vectors_.first.cend(), vectors_.second.cend());
}
