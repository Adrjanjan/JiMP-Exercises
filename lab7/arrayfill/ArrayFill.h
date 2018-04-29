//
// Created by adrja on 27.04.2018.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <vector>
#include <cstdlib>
#include <random>
#include <bits/unique_ptr.h>

namespace arrays {

    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    class IncrementalFill : public ArrayFill {
    public:
        explicit IncrementalFill(int start, int step = 1);

        int Value(int index) const override;

    private:
        int start_, step_, value_;
    };

    class RandomFill : public ArrayFill {
    public:
        RandomFill(std::unique_ptr<std::default_random_engine> generator,
                   std::unique_ptr<std::uniform_int_distribution<int>> distribution);

        int Value(int index) const override;

    private:
        std::unique_ptr<std::default_random_engine> generator_;
        std::unique_ptr<std::uniform_int_distribution<int>> distribution_;
    };

    class SquaredFill : public ArrayFill {
    public:
        explicit SquaredFill(int a = 1, int b = 0);

        int Value(int index) const override;

    private:
        int a_, b_;
    };

    class UniformFill : public ArrayFill {
    public:
        explicit UniformFill(int value = 0);

        int Value(int index) const override;

    private:
        int value_;
    };


    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);
}

#endif //JIMP_EXERCISES_ARRAYFILL_H
