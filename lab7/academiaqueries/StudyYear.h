//
// Created by adrja on 21.04.2018.
//

#ifndef JIMP_EXERCISES_STUDYYEAR_H
#define JIMP_EXERCISES_STUDYYEAR_H

#include <ostream>
#include <istream>

namespace academia {

    class StudyYear {
    public:
        StudyYear();

        StudyYear(size_t);

        friend bool operator<(const StudyYear &l, const StudyYear &r);

        friend bool operator==(const StudyYear &l, const StudyYear &r);

        friend bool operator==(const unsigned int b, const StudyYear &a);

        operator int();

        size_t GetYear() const;

        void SetYear(size_t year);

        StudyYear &operator++();

        StudyYear &operator--();

        friend std::ostream &operator<<(std::ostream &out, const StudyYear &studyYear);

        friend std::istream &operator>>(std::istream &is, StudyYear &studyYear);

    private:
        size_t year_ = 1;
    };

    bool operator<(const StudyYear &l, const StudyYear &r);

    bool operator==(const StudyYear &l, const StudyYear &r);

    bool operator==(const unsigned int b, const StudyYear &a);

    std::ostream &operator<<(std::ostream &out, const StudyYear &studyYear);

    std::istream &operator>>(std::istream &is, StudyYear &studyYear);

}

#endif //JIMP_EXERCISES_STUDYYEAR_H