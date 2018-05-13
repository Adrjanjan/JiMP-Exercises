//
// Created by adrja on 05/05/2018.
//

#include "IterableIterator.h"

////--EnumerateIterator----------------------------------------------------------------------------------------------------////
utility::EnumerateIterator::EnumerateIterator(std::vector<int>::const_iterator left_begin,
                                              std::vector<std::string>::const_iterator right_begin) :
        left_begin_(left_begin),
        right_begin_(right_begin) {}

std::pair<int, std::string> utility::EnumerateIterator::Dereference() const {
    return std::make_pair(*left_begin_, *right_begin_);
}

utility::IterableIterator &utility::EnumerateIterator::Next() {
    ++right_begin_;
    ++left_begin_;
    return *this;
}

bool utility::EnumerateIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    if (auto temp = dynamic_cast<EnumerateIterator *>(other.get())) {
        return left_begin_ != temp->left_begin_ || right_begin_ != temp->right_begin_;
    }
    return true;
}

////--ProductIterator----------------------------------------------------------------------------------------------------////
utility::ProductIterator::ProductIterator(std::vector<int>::const_iterator left_begin,
                                          std::vector<std::string>::const_iterator right_begin) :
        left_begin_(left_begin),
        right_begin_(right_begin) {}

std::pair<int, std::string> utility::ProductIterator::Dereference() const {
    return std::make_pair(*left_begin_, *right_begin_);
}

utility::IterableIterator &utility::ProductIterator::Next() {
    ++right_begin_;
    ++left_begin_;
    return *this;
}

bool utility::ProductIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    if (auto temp = dynamic_cast<ProductIterator *>(other.get())) {
        return left_begin_ != temp->left_begin_ || right_begin_ != temp->right_begin_;
    }
    return true;
}

////--ZipperIterator----------------------------------------------------------------------------------------------------////
utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin,
                                        std::vector<std::string>::const_iterator right_begin,
                                        std::vector<int>::const_iterator left_end,
                                        std::vector<std::string>::const_iterator right_end) :
        left_begin_(left_begin),
        right_begin_(right_begin) {}

utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin,
                                        std::vector<std::string>::const_iterator right_begin) :
        left_begin_(left_begin),
        right_begin_(right_begin) {}

std::pair<int, std::string> utility::ZipperIterator::Dereference() const {
    return std::make_pair(*left_begin_, *right_begin_);
}

utility::IterableIterator &utility::ZipperIterator::Next() {
    ++left_begin_;
    ++right_begin_;

    return *this;
}

bool utility::ZipperIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
    if (auto temp = dynamic_cast<ZipperIterator *>(other.get())) {
        return left_begin_ != temp->left_begin_ || right_begin_ != temp->right_begin_;
    }
    return true;
}


