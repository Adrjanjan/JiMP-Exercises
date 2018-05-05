//
// Created by adrja on 05/05/2018.
//

#ifndef JIMP_EXERCISES_ITERABLEITERATOR_H
#define JIMP_EXERCISES_ITERABLEITERATOR_H

#include <string>
#include <vector>
#include <memory>

namespace utility {

    class IterableIterator {
    public:
        virtual std::pair<int, std::string> Dereference() const = 0;                      // sth = *it
        virtual IterableIterator &Next() =0;                                              // ++it
        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const =0;  // it != other
        virtual ~IterableIterator() = default;
    };

    class EnumerateIterator : public IterableIterator {
    public:
        explicit EnumerateIterator(std::vector<int>::const_iterator left_begin,
                                   std::vector<std::string>::const_iterator right_begin);

        std::pair<int, std::string> Dereference() const override;                        // sth = *it
        IterableIterator &Next() override;                                               // ++it
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override;   // it != other

    private:
        std::vector<int>::const_iterator left_begin_;
        std::vector<std::string>::const_iterator right_begin_;
    };

    class ProductIterator : public IterableIterator {
    public:
        explicit ProductIterator(std::vector<int>::const_iterator left_begin,
                                 std::vector<std::string>::const_iterator right_begin);

        std::pair<int, std::string> Dereference() const override;                        // sth = *it
        IterableIterator &Next() override;                                               // ++it
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override;   // it != other

    private:
        std::vector<int>::const_iterator left_begin_;
        std::vector<std::string>::const_iterator right_begin_;
    };

    class ZipperIterator : public IterableIterator {
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                                std::vector<std::string>::const_iterator right_begin,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);

        explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                                std::vector<std::string>::const_iterator right_begin);

        std::pair<int, std::string> Dereference() const override;                       // sth = *it
        IterableIterator &Next() override;                                               // ++it
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override;  // it != other

    private:
        std::vector<int>::const_iterator left_begin_;
        std::vector<std::string>::const_iterator right_begin_;
    };
}


#endif //JIMP_EXERCISES_ITERABLEITERATOR_H
