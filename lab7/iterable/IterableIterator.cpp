//
// Created by adrja on 05/05/2018.
//

#include "IterableIterator.h"

////--EnumerateIterator----------------------------------------------------------------------------------------------------////
utility::EnumerateIterator::EnumerateIterator(std::vector<std::string>::const_iterator right_begin,
                                              std::vector<std::string>::const_iterator right_end) :
        right_current_(right_begin),
        right_end_(right_end),
        counter_(1) {}

std::pair<int, std::string> utility::EnumerateIterator::Dereference() const {
    return std::make_pair(counter_, *right_current_);
}

utility::IterableIterator &utility::EnumerateIterator::Next() {
    ++right_current_;
    ++counter_;
    if (right_current_ == right_end_) {
        --right_current_;
        --counter_;
    }

    return *this;
}

bool utility::EnumerateIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    if (auto temp = dynamic_cast<EnumerateIterator *>(other.get())) {
        return right_current_ != temp->right_current_;
    }
    return true;
}

////--ProductIterator----------------------------------------------------------------------------------------------------////
utility::ProductIterator::ProductIterator(std::vector<int>::const_iterator left_begin,
                                          std::vector<std::string>::const_iterator right_begin,
                                          std::vector<int>::const_iterator left_end,
                                          std::vector<std::string>::const_iterator right_end) :
        left_begin_(left_begin), left_end_(left_end),
        right_begin_(right_begin), right_end_(right_end),
        left_current_(left_begin), right_current_(right_begin) {}

std::pair<int, std::string> utility::ProductIterator::Dereference() const {
    return std::make_pair(*left_current_, *right_current_);
}

utility::IterableIterator &utility::ProductIterator::Next() {
    ++right_current_;
    if (right_current_ == right_end_) {
        right_current_ == right_begin_;
        ++left_current_;

        if (left_current_ == left_end_) {
            right_current_ = right_end_;
            left_current_ == left_end_;
        }
    }
    return *this;
}

bool utility::ProductIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    if (auto temp = dynamic_cast<ProductIterator *>(other.get())) {
        return left_current_ != temp->left_current_ || right_current_ != temp->right_current_;
    }
    return true;
}

////--ZipperIterator----------------------------------------------------------------------------------------------------////
utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin,
                                        std::vector<std::string>::const_iterator right_begin,
                                        std::vector<int>::const_iterator left_end,
                                        std::vector<std::string>::const_iterator right_end) :
        left_begin_(left_begin),
        left_end_(left_end),
        right_begin_(right_begin),
        right_end_(right_end) {}

std::pair<int, std::string> utility::ZipperIterator::Dereference() const {
    return std::make_pair(*left_begin_, *right_begin_);
}

utility::IterableIterator &utility::ZipperIterator::Next() {
    ++left_begin_;
    if (left_begin_ == left_end_) --left_begin_;

    ++right_begin_;
    if (right_begin_ == right_end_) --right_begin_;

    return *this;
}

bool utility::ZipperIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
    if (auto temp = dynamic_cast<ZipperIterator *>(other.get())) {
        return left_begin_ != temp->left_begin_ || right_begin_ != temp->right_begin_;
    }
    return true;
}