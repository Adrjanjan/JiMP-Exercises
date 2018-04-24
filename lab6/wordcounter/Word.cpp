//
// Created by adrja on 21.04.2018.
//

#include "Word.h"

datastructures::Word::Word() = default;

datastructures::Word::Word(std::string str) {
    word_ = std::move(str);
}

void datastructures::Word::Set(std::string str) {
    word_ = std::move(str);
}

std::string datastructures::Word::Get() {
    return word_;
}

bool datastructures::operator==(const datastructures::Word &l, const datastructures::Word &r) {
    return l.word_ == r.word_;
}

bool datastructures::operator>(const datastructures::Word &l, const datastructures::Word &r) {
    return l.word_ > r.word_;
}

bool datastructures::operator<(const datastructures::Word &l, const datastructures::Word &r) {
    return l.word_ < r.word_;
}

