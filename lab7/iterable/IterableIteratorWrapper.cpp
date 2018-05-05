//
// Created by adrja on 05/05/2018.
//

#include "IterableIteratorWrapper.h"

////--IterableIteratorWrapper----------------------------------------------------------------------------------------------------////

utility::IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<utility::IterableIterator> iterator) {
    iterator_ = std::move(iterator);
}

bool utility::IterableIteratorWrapper::operator!=(const utility::IterableIteratorWrapper &other) const {
    return iterator_->NotEquals(other.iterator_);
}

std::pair<int, std::string> utility::IterableIteratorWrapper::operator*() const {
    return iterator_->Dereference();
}

utility::IterableIteratorWrapper &utility::IterableIteratorWrapper::operator++() {
    iterator_->Next();
    return *this;
}