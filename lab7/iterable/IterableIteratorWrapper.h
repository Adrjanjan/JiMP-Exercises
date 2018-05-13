//
// Created by adrja on 05/05/2018.
//

#ifndef JIMP_EXERCISES_ITERABLEITERATORWRAPPER_H
#define JIMP_EXERCISES_ITERABLEITERATORWRAPPER_H


#include "IterableIterator.h"

namespace utility {

    class IterableIteratorWrapper {
    public:
        explicit IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator);

        bool operator!=(const IterableIteratorWrapper &other) const;

        std::pair<int, std::string> operator*() const;

        IterableIteratorWrapper &operator++();

    private:
        std::unique_ptr<IterableIterator> iterator_;
    };

}
#endif //JIMP_EXERCISES_ITERABLEITERATORWRAPPER_H
