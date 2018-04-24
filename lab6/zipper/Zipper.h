//
// Created by adrja on 21.04.2018.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H

#include <string>
#include <vector>

namespace datastructures {
    using ::std::string;
    using ::std::pair;
    using ::std::vector;

    class ZipperIterator {
    public:
        ZipperIterator(std::vector<std::string>::iterator is, std::vector<int>::iterator ii);

        pair<string, int> operator*() const;

        ZipperIterator &operator++();

        bool operator!=(const ZipperIterator &other) const;

    private:
        std::pair<std::vector<std::string>::iterator, std::vector<int>::iterator> zipped_it_;
    };

    class Zipper {
    public:
        static Zipper zip(const vector<string> &vs, const vector<int> &vi);

        ZipperIterator begin();

        ZipperIterator end();

    private:
        std::pair<std::vector<std::string>, std::vector<int>> zipped_;
    };
}

#endif //JIMP_EXERCISES_ZIPPER_H
