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

        std::string Id();

        std::string FirstName();

        std::string LastName();

        std::string Program();

        StudyYear Year();

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
}

#endif //JIMP_EXERCISES_STUDENT_H
