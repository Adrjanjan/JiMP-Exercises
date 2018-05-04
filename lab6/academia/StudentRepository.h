//
// Created by adrja on 21.04.2018.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <vector>
#include <memory>
#include "StudyYear.h"
#include "Student.h"
#include "StudentRepositoryQueries.h"


namespace academia {

    class StudentRepository {
    public:
        StudentRepository();

        StudentRepository(const std::initializer_list<Student> &initializer_list) : students_(initializer_list) {}

        size_t StudentCount();

        friend bool operator==(const StudentRepository &l, const StudentRepository &r);

        Student &operator[](std::string student_id);

        std::vector<Student> FindByQuery(std::unique_ptr<Query> query);

    private:
        std::vector<Student> students_;
    };

}

#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
