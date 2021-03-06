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

//// przynajmniej imię i nazwisko
//// każdy człon imienia i nazwiska z Wielskiej litery i pozostałe małe
//// Imię nie może zawierać znaków cyfr specjalnych
//// WIek studenta w Zakresie 10-100 lar
//// kierunek studiów z zakresu {"informatyka", "ekonomia", "matematyka","fizyka","filozofia"}
//// nazwy wyjątków
//// - InvalidNameSurname
//// - InvalidNameCharacters
//// - InvalidAge
//// - InvalidProgram
//// dopisać main wstawiający poprawnie skonstuowanych studentów do repozytorium

std::string academia::Student::Id() const {
    return id_;
}

std::string academia::Student::FirstName() const {
    return first_name_;
}

std::string academia::Student::LastName() const {
    return last_name_;
}

std::string academia::Student::Program() const {
    return program_;
}

academia::StudyYear academia::Student::Year() const {
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
           l.year_.GetYear() == r.year_.GetYear();
}

bool academia::operator<(const Student &l, const Student &r) {
    return l.Id() < r.Id();
}

academia::InvalidNameSurname::InvalidNameSurname(const std::string &name, const std::string &surname)
        : AcademiaDataValidationError(
        "Can't create student's with wrong name:" + name + " or surnname: " + surname + ".") {}

academia::InvalidNameCharacters::InvalidNameCharacters(const std::string &name)
        : AcademiaDataValidationError("Can't create student's name with wrong chars: " + name + " .") {}

academia::InvalidAge::InvalidAge(const size_t &age)
        : AcademiaDataValidationError(
        "Can't create student with age out of rescricted bounds (10-100):" + std::to_string(age)) {}

academia::InvalidProgram::InvalidProgram(const std::string &program)
        : AcademiaDataValidationError("Can't create student with wrong program:" + program + ".") {}

}
