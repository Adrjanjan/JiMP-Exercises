//
// Created by adrja on 02.04.2018.
//

#include "Point.h"

namespace geometry {
    std::array<Point, 4> Square::GetPoints() {
        return vertexes_;
    }

    Square::~Square() = default;

    Point::Point() : x_(0), y_(0) {
        cout << "Konstruktor bezparametrowy" << endl;
    }

    Point::Point(double x, double y) {
        cout << "Konstruktor parametrowy" << endl;
        x_ = x;
        y_ = y;
    }

    Point::~Point() {
        cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci! " << x_ << " , " << y_;
        cout << endl;
    }

    double Point::Distance(const Point &other) const {
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
    }

    void Point::ToString(ostream *out) const {
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    double Point::GetX() const {
        return this->x_;
    }

    double Point::GetY() const {
        return this->y_;
    }

    Point &Point::SetX(double x) {
        this->x_ = x;
        return *this;
    }

    Point &Point::SetY(double y) {
        this->y_ = y;
        return *this;
    }

    double Distance(const Point &a, const Point &b) {
        return sqrt(pow(a.GetX() - b.GetX(), 2) + pow(a.GetY() - b.GetY(), 2));
    }
}
