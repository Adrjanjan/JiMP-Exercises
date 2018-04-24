//
// Created by adrja on 21.04.2018.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H

namespace datastructures {

    class Counts {
    public:
        Counts();

        Counts(size_t);

        size_t Get() const;

        void Set(size_t size);

        Counts &operator++();

        friend bool operator==(const Counts &l, const Counts &r);


    private:
        size_t counts_;
    };

    bool operator==(const Counts &l, const Counts &r);
}
#endif //JIMP_EXERCISES_COUNTS_H
