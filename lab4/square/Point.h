//
// Created by adrjan on 2018-04-01.
//

#ifndef PROJECTNAME_PATH_POINT_H_
#define PROJECTNAME_PATH_POINT_H_
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
#endif  // PROJECTNAME_PATH_POINT_H_