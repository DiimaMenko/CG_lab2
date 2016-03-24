#include "point.h"

Point::Point()
{
    this->xp = 0.0;
    this->yp = 0.0;
}

Point::Point(double x, double y){
    this->xp = x;
    this->yp = y;
}

double Point::x(){
    return this->xp;
}

double Point::y(){
    return this->yp;
}

void Point::setPoint(double x, double y){
    this->xp = x;
    this->yp = y;
}

void Point::setPoint(Point *point){
    this->xp = point->x();
    this->yp = point->y();
}

void Point::setX(double x){
    this->xp = x;
}

void Point::setY(double y){
    this->yp = y;
}

bool operator==(const Point &p1, const Point &p2){
    return p1.xp == p2.xp && p1.yp == p2.yp;
}

bool operator!=(const Point &p1, const Point &p2){
    return p1.xp != p2.xp || p1.yp != p2.yp;
}
