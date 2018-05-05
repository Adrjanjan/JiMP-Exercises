//
// Created by adrja on 27.04.2018.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H


#include "IterableIteratorWrapper.h"

namespace utility {

    class Iterable {
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin() const =0;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const =0;

        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;

        std::pair<std::vector<int>, std::vector<std::string>> vectors_;
    };

    class Enumerate : public Iterable {
    public:
        explicit Enumerate(const std::vector<std::string> &vs);

        std::unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;
    };

    class Product : public Iterable {
    public:
        Product(const std::vector<int> &vi, const std::vector<std::string> &vs);

        std::unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;
    };

    class Zipper : public Iterable {
    public:
        Zipper(const std::vector<int> &vi, const std::vector<std::string> &vs);

        std::unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;
    };

}
#endif //JIMP_EXERCISES_ITERABLE_H
