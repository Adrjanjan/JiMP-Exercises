//
// Created by adrjan on 2018-04-01.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

//TODO: Napisz klasę Square, która będzie posiadać jako pola obiekty klasy Point (4 wierzchołki). Napisz metody obliczające obwód (Circumference) i pole kwadratu (Area).

#include "Point.h"

namespace geometry {
    class Square {
    public:
        GetArea();

        GetCircumference();

    protected:

    private:
        geometry::Point a_, b_, c_, d_;

    };
}

#endif //JIMP_EXERCISES_SQUARE_H
