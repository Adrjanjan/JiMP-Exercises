//
// Created by adrja on 21.04.2018.
//

#include "StudyYear.h"


academia::StudyYear::StudyYear() = default;

academia::StudyYear::StudyYear(size_t year) : year_(year) {}

bool academia::operator<(const academia::StudyYear &l, const academia::StudyYear &r) {
    return l.year_ < r.year_;
}

bool academia::operator==(const academia::StudyYear &l, const academia::StudyYear &r) {
    return l.year_ == r.year_;
}

bool academia::operator==(const unsigned int b, const academia::StudyYear &a) {
    return b == a.year_;
}

academia::StudyYear::operator int() {
    return static_cast<int>(year_);
}

size_t academia::StudyYear::GetYear() const {
    return year_;
}

void academia::StudyYear::SetYear(size_t year) {
    year_ = year;
}

academia::StudyYear &academia::StudyYear::operator++() {
    ++year_;
    return *this;
}

academia::StudyYear &academia::StudyYear::operator--() {
    --year_;
    return *this;
}

std::ostream &academia::operator<<(std::ostream &out, const academia::StudyYear &studyYear) {
    out << studyYear.year_;
    return out;
}

std::istream &academia::operator>>(std::istream &is, academia::StudyYear &studyYear) {
    is >> studyYear.year_;
    return is;
}


