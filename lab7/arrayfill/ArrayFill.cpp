//
// Created by adrja on 27.04.2018.
//

#include "ArrayFill.h"

namespace arrays {

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; ++i) {
            v->emplace_back(filler.Value(i));
        }
    }

    UniformFill::UniformFill(int value) {
        value_ = value;

    }

    int UniformFill::Value(int index) const {
        return value_;
    }


    IncrementalFill::IncrementalFill(int start, int step) {
        start_ = start;
        step_ = step;
    }

    int IncrementalFill::Value(int index) const {
        return start_ + index * step_;
    }


    RandomFill::RandomFill(std::unique_ptr<std::default_random_engine> generator,
                           std::unique_ptr<std::uniform_int_distribution<int>> distribution) {

        generator_ = std::move(generator);
        distribution_ = std::move(distribution);
    }

    int RandomFill::Value(int index) const {
        return (*distribution_)(*generator_);
    }

    SquaredFill::SquaredFill(int a, int b) {
        a_ = a;
        b_ = b;
    }

    int SquaredFill::Value(int index) const {
        return a_ * index * index + b_;
    }

}