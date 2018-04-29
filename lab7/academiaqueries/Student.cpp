//
// Created by adrja on 21.04.2018.
//

#include "Student.h"
#include <utility>

using ::academia::Student;

Student::Student() = default;

Student::Student(std::string id,
                 std::string first_name,
                 std::string last_name,
                 std::string program,
                 size_t year) :
        id_(std::move(id)),
        first_name_(std::move(first_name)),
        last_name_(std::move(last_name)),
        program_(std::move(program)),
        year_(year) {}


std::string academia::Student::Id() {
    return id_;
}

std::string academia::Student::FirstName() {
    return first_name_;
}

std::string academia::Student::LastName() {
    return last_name_;
}

std::string academia::Student::Program() {
    return program_;
}

academia::StudyYear academia::Student::Year() {
    return year_;
}

void academia::Student::Id(const std::string &id) {
    id_ = id;
}

void academia::Student::Program(const std::string &program) {
    program_ = program;
}

void academia::Student::ChangeFirstName(const std::string &first_name) {
    first_name_ = first_name;
}

void academia::Student::ChangeLastName(const std::string &last_name) {
    last_name_ = last_name;
}

void academia::Student::ChangeYear(const academia::StudyYear &year) {
    year_ = year;
}

bool academia::operator==(const Student &l, const Student &r) {
    return l.id_ == r.id_ &&
           l.first_name_ == r.first_name_ &&
           l.last_name_ == r.last_name_ &&
           l.program_ == r.program_ &&
           l.year_ == r.year_;
}
