#ifndef Segment_H
#define Segment_H

#include <point.h>
#include <QtMath>
#include <QString>

#define PI 3.14159265
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
#define min(X, Y) (((X) < (Y)) ? (X) : (Y))

class Segment
{
private:
    Point *startPoint;
    Point *endPoint;
    Point *intersectPoint;
    double A;
    double B;
    double C;
public:
    Segment();
    Segment(double x1, double y1, double x2, double y2);
    Segment(Point *p1, Point *p2);
    void setSegment(double x1, double y1, double x2, double y2);
    void setSegment(Point *p1, Point *p2);
    Point *getStart();
    Point *getEnd();
    double getA();
    double getB();
    double getC();

    bool equal(Segment *seg);
    bool parallelLines (Segment *seg);
    bool intersect (Segment *seg);
    bool range (Segment *seg, Point *inter);
    double Angle(Segment *seg);
    long double getDet (long double a, long double b, long double c, long double d);
    int test(Segment *seg);
    ~Segment(){}
};

#endif // Segment_H
