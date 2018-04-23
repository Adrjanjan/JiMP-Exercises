//
// Created by adrja on 16.04.2018.
//

#include "TextPool.h"

using ::pool::TextPool;

size_t TextPool::StoredStringCount() const {
    return pool_.size();
}

std::experimental::string_view TextPool::Intern(const std::string &str) {

    std::experimental::string_view phrase = str;
    auto found = pool_.find(str);

    if (found == pool_.end()) {
        pool_.emplace(phrase);
    }
    return phrase;
}

TextPool::TextPool(const std::initializer_list<std::experimental::string_view> &pool) : pool_(pool) {
}

TextPool::TextPool() = default;

TextPool::TextPool(TextPool &&other) {
    pool_ = std::move(other.pool_);
}

TextPool &TextPool::operator=(TextPool &&other) {
    if (this == &other) {
        return *this;
    }
    pool_ = std::move(other.pool_);
}
