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
    return std::make_unique<EnumerateIterator>(vs_.cbegin(), vs_.cend());
}

std::unique_ptr<utility::IterableIterator> utility::Enumerate::ConstEnd() const {
    return std::make_unique<EnumerateIterator>(vs_.cend(), vs_.cend());
}

utility::Enumerate::Enumerate(const std::vector<std::string> &vs) : vs_(vs) {};

////--Product---------------------------------------------------------------------------------------------------////
utility::Product::Product(const std::vector<int> &vi, const std::vector<std::string> &vs) : vi_(vi), vs_(vs) {}

std::unique_ptr<utility::IterableIterator> utility::Product::ConstBegin() const {
    return std::make_unique<ProductIterator>(vi_.begin(), vs_.cbegin(), vi_.cend(), vs_.cend());
}

std::unique_ptr<utility::IterableIterator> utility::Product::ConstEnd() const {
    return std::make_unique<ProductIterator>(vi_.cend(), vs_.cend(), vi_.cend(), vs_.cend());
}

////--Zipper----------------------------------------------------------------------------------------------------////
utility::Zipper::Zipper(const std::vector<int> &vi, const std::vector<std::string> &vs) : vi_(vi), vs_(vs) {}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstBegin() const {
    return std::make_unique<ZipperIterator>(vi_.cbegin(), vs_.cbegin(), vi_.cend(), vs_.cend());
}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstEnd() const {
    return std::make_unique<ZipperIterator>(vi_.cend(), vs_.cend(), vi_.cend(), vs_.cend());
}
