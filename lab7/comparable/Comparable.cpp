//
// Created by adrja on 27.04.2018.
//
#include "StudentRepository.h"
#include "Comparable.h"


bool academia::ByFirstNameAscending::IsLess(const academia::Student &left, const academia::Student &right) {
    return left.FirstName() < right.FirstName();
}

bool academia::ByFirstNameDescending::IsLess(const academia::Student &left, const academia::Student &right) {
    return left.FirstName() > right.FirstName();
}

bool academia::ByLastNameAscending::IsLess(const academia::Student &left, const academia::Student &right) {
    return left.LastName() < right.LastName();
}

bool academia::ByProgramAscendingEmptyFirst::IsLess(const academia::Student &left, const academia::Student &right) {
    if (left.Program().empty()) return true;
    if (right.Program().empty()) return false;
    return left.Program() < right.Program();
}

bool academia::ByProgramAscendingEmptyLast::IsLess(const academia::Student &left, const academia::Student &right) {
    if (left.Program().empty()) return false;
    if (right.Program().empty()) return true;
    return left.Program() < right.Program();
}

bool academia::StudentComparator::operator()(const academia::Student &left, const academia::Student &right) {
    return this->IsLess(left, right);
}
