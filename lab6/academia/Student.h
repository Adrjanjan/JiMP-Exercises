//
// Created by adrja on 21.04.2018.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H


#include <string>
#include "StudyYear.h"

namespace academia {

    class Student {
    public:
        Student();

        Student(std::string id, std::string first_name, std::string last_name, std::string program, size_t year);

        friend bool operator==(const Student &l, const Student &r);

        friend bool operator<(const Student &l, const Student &r);

        std::string Id() const;

        std::string FirstName() const;

        std::string LastName() const;

        std::string Program() const;

        StudyYear Year() const;

        void Id(const std::string &);

        void Program(const std::string &);

        void ChangeFirstName(const std::string &);

        void ChangeLastName(const std::string &);

        void ChangeYear(const StudyYear &);

    private:
        std::string id_, first_name_, last_name_, program_;
        StudyYear year_;
    };

    bool operator==(const Student &l, const Student &r);

    bool operator<(const Student &l, const Student &r);

    class AcademiaDataValidationError : public std::invalid_argument {
    public:
        explicit AcademiaDataValidationError(const std::string &message);
    };

    class InvalidNameSurname : public AcademiaDataValidationError {
    public:
        InvalidNameSurname(const std::string &name, const std::string &surname)
    };

    class InvalidNameCharacters : public AcademiaDataValidationError {
    public:
        explicit InvalidNameCharacters(const std::string &name)
    };

    class InvalidAge : public AcademiaDataValidationError {
    public:
        explicit InvalidAge(const size_t &age);
    };

    class InvalidProgram : public AcademiaDataValidationError {
    public:
        explicit InvalidProgram(const std::string &program)
    };
}

#endif //JIMP_EXERCISES_STUDENT_H
