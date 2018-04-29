//
// Created by adrja on 27.04.2018.
//

#ifndef JIMP_EXERCISES_COMPARABLE_H
#define JIMP_EXERCISES_COMPARABLE_H

#include <StudentRepository.h>

namespace academia {

    class StudentComparator {
    public:
        virtual bool IsLess(const Student &left, const Student &right) = 0;

        virtual bool operator()(const Student &left, const Student &right);
    };

    class ByFirstNameAscending : public StudentComparator {
    public:
        ByFirstNameAscending() = default;

        virtual bool IsLess(const Student &left, const Student &right) override;
    };


    class ByFirstNameDescending : public StudentComparator {
    public:
        ByFirstNameDescending() = default;

        virtual bool IsLess(const Student &left, const Student &right) override;
    };


    class ByLastNameAscending : public StudentComparator {
    public:
        virtual bool IsLess(const Student &left, const Student &right) override;
    };

    class ByProgramAscendingEmptyFirst : public StudentComparator {
    public:
        virtual bool IsLess(const Student &left, const Student &right) override;
    };

    class ByProgramAscendingEmptyLast : public StudentComparator {
    public:
        virtual bool IsLess(const Student &left, const Student &right) override;
    };
}

#endif //JIMP_EXERCISES_COMPARABLE_H
