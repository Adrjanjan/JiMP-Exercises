//
// Created by adrja on 21.04.2018.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H

namespace datastructures {


    class ZipperIterator {
    public:
        pair<string, int> operator*() const; //wmagane w linii 74
        ZipperIterator &operator++(); //wymagane w linii 73 for(_;_;TU)
        bool operator!=(const ZipperIterator &other) const; //wymagane w linii 73 for(_;TU;_)
    private:
        //TODO
    };

//umożliwia przeglądanie dwóch wektorów na raz, w jednej pętli range-for
    class Zipper {
    public:
        static Zipper zip(const vector <string> &vs, const vector<int> &vi);

        ZipperIterator begin(); //wymagane w linii 73 for(TU;_;_)
        ZipperIterator end(); //wymagane w linii 73 for(_;TU;_)
    private:
        //TODO
    };
}

#endif //JIMP_EXERCISES_ZIPPER_H
