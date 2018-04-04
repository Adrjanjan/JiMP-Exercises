//
// Created by adrja on 02.04.2018.
//

#include "Square.h"
#include <cmath>
#include <iostream>

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

        int correct_points = 6;
        double dist = std::fmin(std::fmin(_a.Distance(_b), _a.Distance(_c)), _a.Distance(_d));

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (vertexes_[i].Distance(vertexes_[j]) == dist) {
                    --correct_points;
                }
            }
        }
        if (correct_points != 0) {
            for (auto &i: vertexes_) {
                i.SetX(0).SetY(0);
            }
        }
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

        int correct_points = 8;
        double dist = std::fmin(std::fmin(_a.Distance(_b), _a.Distance(_c)), _a.Distance(_d));

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (vertexes_[i].Distance(vertexes_[j]) == dist) {
                    --correct_points;
                }
            }
        }
        if (correct_points != 0) {
            for (auto &i: vertexes_) {
                i.SetX(0).SetY(0);
            }
        }
    }

    void Square::SetPoints(const std::array<Point, 4> &pts) {
        vertexes_ = pts;
        int correct_points = 8;
        double dist = std::fmin(std::fmin(vertexes_[0].Distance(vertexes_[1]), vertexes_[0].Distance(vertexes_[2])),
                                vertexes_[0].Distance(vertexes_[3]));

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (vertexes_[i].Distance(vertexes_[j]) == dist) {
                    --correct_points;
                }
            }
        }
        if (correct_points != 0) {
            for (auto &i: vertexes_) {
                i.SetX(0).SetY(0);
            }
        }
    }

    std::array<Point, 4> Square::GetPoints() {
        return vertexes_;
    }

    Square::~Square() = default;
}