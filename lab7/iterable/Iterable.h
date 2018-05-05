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

    private:
        std::unique_ptr<IterableIteratorWrapper> iterator_ptr_;
    };

    class Enumerate : public Iterable {
    public:
        explicit Enumerate(const std::vector<std::string> &vs);

        std::unique_ptr<IterableIterator> ConstBegin() const override;

        std::unique_ptr<IterableIterator> ConstEnd() const override;

    private:
        const std::vector<std::string> &vs_;
    };

    class Product : public Iterable {
    public:
        Product(const std::vector<int> &vi, const std::vector<std::string> &vs);

        std::unique_ptr<IterableIterator> ConstBegin() const override;

        std::unique_ptr<IterableIterator> ConstEnd() const override;

    private:
        const std::vector<int> &vi_;
        const std::vector<std::string> &vs_;
    };

    class Zipper : public Iterable {
    public:
        Zipper(const std::vector<int> &vi, const std::vector<std::string> &vs);

        std::unique_ptr<IterableIterator> ConstBegin() const override;

        std::unique_ptr<IterableIterator> ConstEnd() const override;

    private:
        const std::vector<int> &vi_;
        const std::vector<std::string> &vs_;
    };

}
#endif //JIMP_EXERCISES_ITERABLE_H
