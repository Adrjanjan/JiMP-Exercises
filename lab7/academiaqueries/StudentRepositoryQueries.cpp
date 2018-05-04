//
// Created by adrja on 27.04.2018.
//

#include "StudentRepositoryQueries.h"

bool academia::ByFirstName::Accept(const academia::Student &student) const {
    return student.FirstName() == first_name_;
}

bool academia::ByLastName::Accept(const academia::Student &student) const {
    return student.LastName() == last_name_;
}

bool academia::ByOneOfPrograms::Accept(const academia::Student &student) const {

    for (const auto &i : programs_) {
        if (student.Program() == i) {
            return true;
        }
    }
    return false;
}

bool academia::ByYearLowerOrEqualTo::Accept(const academia::Student &student) const {
    return student.Year().GetYear() <= year_.GetYear();
}

academia::OrQuery::OrQuery(std::unique_ptr<academia::Query> left, std::unique_ptr<academia::Query> right) : left_(
        std::move(left)),
                                                                                                            right_(std::move(
                                                                                                                    right)) {}

bool academia::OrQuery::Accept(const academia::Student &student) const {
    return left_->Accept(student) || right_->Accept(student);
}

academia::AndQuery::AndQuery(std::unique_ptr<academia::Query> left, std::unique_ptr<academia::Query> right) : left_(
        std::move(left)),
                                                                                                              right_(std::move(
                                                                                                                      right)) {}

bool academia::AndQuery::Accept(const academia::Student &student) const {
    return left_->Accept(student) && right_->Accept(student);
}

