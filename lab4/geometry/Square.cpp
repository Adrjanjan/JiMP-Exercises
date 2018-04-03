//
// Created by adrja on 02.04.2018.
//

#include "Square.h"

namespace geometry {
    using ::std::ostream;
    using ::std::endl;
    using ::std::pow;
    using ::std::sqrt;
    using ::std::cout;

    Square::Square() = default;

    Square::Square(const Point &_a, const Point &_b, const Point &_c, const Point &_d) {
        vertexes_[0] = _a;
        vertexes_[1] = _b;
        vertexes_[2] = _c;
        vertexes_[3] = _d;
    }

    double Square::Area() {
        return pow(vertexes_[0].Distance(vertexes_[1]), 2);
    }

    double Square::Circumference() {
        return 4 * vertexes_[0].Distance(vertexes_[1]);
    }

    void Square::SetPoints(const Point &_a, const Point &_b, const Point &_c, const Point &_d) {
        vertexes_[0] = _a;
        vertexes_[1] = _b;
        vertexes_[2] = _c;
        vertexes_[3] = _d;
    }

    void Square::SetPoints(const std::array<Point, 4> &pts) {
        vertexes_ = pts;
    }
}