//
// Created by adrja on 02.04.2018.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

namespace geometry {

    class Point {
    public:
        Point();

        Point(double x, double y);

        ~Point();

        void ToString(std::ostream *out) const;

        double Distance(const Point &other) const;

        double GetX() const;

        double GetY() const;

        Point &SetX(double x);

        Point &SetY(double y);

    private:
        double x_, y_;
    };
}


#endif //JIMP_EXERCISES_POINT_H
