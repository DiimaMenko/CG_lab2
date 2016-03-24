#ifndef POINT_H
#define POINT_H


class Point
{
private:
    double xp;
    double yp;
public:
    Point();
    Point(double x, double y);
    double x();
    double y();
    void setPoint(Point *point);
    void setPoint(double x, double y);
    void setX(double x);
    void setY(double y);

    friend bool operator==(const Point &, const Point &);
    friend bool operator!=(const Point &, const Point &);
};

#endif // POINT_H
