//
// Created by adrja on 02.04.2018.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include "Point.h"
#include <array>

namespace geometry {

    class Square {
    public:
        Square();

        Square(const Point &_a, const Point &_b, const Point &_c, const Point &_d);

        double Area();

        double Circumference();

        void SetPoints(const Point &_a, const Point &_b, const Point &_c, const Point &_d);

        void SetPoints(const std::array<Point, 4> &pts);

        std::array<Point, 4> GetPoints();

        ~Square();

    protected:
    private:
        std::array<Point, 4> vertexes_;
    };
}
#endif //JIMP_EXERCISES_SQUARE_H
