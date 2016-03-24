#include "Segment.h"

Segment::Segment(){
    this->startPoint = new Point(0, 0);
    this->endPoint = new Point(0, 0);
    this->A = this->endPoint->y() - this->startPoint->y();
    this->B = this->endPoint->x() - this->startPoint->x();
    this->C = this->startPoint->x() * this->endPoint->y() - this->endPoint->x() * this->startPoint->y();
}

Segment::Segment(double x1, double y1, double x2, double y2){
    this->startPoint = new Point(x1, y1);
    this->endPoint = new Point(x2, y2);
    this->A = this->endPoint->y() - this->startPoint->y();
    this->B = this->endPoint->x() - this->startPoint->x();
    this->C = this->startPoint->x() * this->endPoint->y() - this->endPoint->x() * this->startPoint->y();
}

Segment::Segment(Point *p1, Point *p2){
    this->startPoint = new Point();
    this->endPoint = new Point();
    startPoint = p1;
    endPoint = p2;
    this->A = this->endPoint->y() - this->startPoint->y();
    this->B = this->endPoint->x() - this->startPoint->x();
    this->C = this->startPoint->x() * this->endPoint->y() - this->endPoint->x() * this->startPoint->y();
}

void Segment::setSegment(double x1, double y1, double x2, double y2){
    this->startPoint->setX(x1);
    this->startPoint->setY(y1);
    this->endPoint->setX(x2);
    this->endPoint->setY(y2);
    this->A = this->endPoint->y() - this->startPoint->y();
    this->B = this->endPoint->x() - this->startPoint->x();
    this->C = this->startPoint->x() * this->endPoint->y() - this->endPoint->x() * this->startPoint->y();
}

void Segment::setSegment(Point *p1, Point *p2){
    this->startPoint->setPoint(p1);
    this->endPoint->setPoint(p2);
    this->A = this->endPoint->y() - this->startPoint->y();
    this->B = this->endPoint->x() - this->startPoint->x();
    this->C = this->startPoint->x() * this->endPoint->y() - this->endPoint->x() * this->startPoint->y();
}

Point* Segment::getEnd(){
    return this->endPoint;
}

Point* Segment::getStart(){
    return this->startPoint;
}

double Segment::getA(){
    return this->A;
}

double Segment::getB(){
    return this->B;
}

double Segment::getC(){
    return this->C;
}

bool Segment::equal(Segment *seg){
    return abs (getDet (this->A, this->C, seg->getA(), seg->getC())) == 0
            && abs (getDet (this->B, this->C, seg->getB(), seg->getC())) == 0;
}

long double Segment::getDet(long double a, long double b, long double c, long double d){
    return a * d - b * c;
}

bool Segment::parallelLines (Segment *seg)
{
    return getDet (this->A, this->B, seg->getA(), seg->getB()) == 0;
}

bool Segment::intersect(Segment *seg)
{
    long double zn = getDet (this->A, this->B, seg->getA(), seg->getB());
    Point *inter = new Point(getDet (getC(), getB(), seg->getC(), seg->getB()) / zn, - getDet (this->A, this->C, seg->getA(), seg->getC()) / zn);
    if(range(seg, inter)){
        this->intersectPoint = inter;
        return true;
    }
    return false;
}

bool Segment::range (Segment *seg ,Point *inter)
{
    bool    x1 = false,
            y1 = false,
            x2 = false,
            y2 = false,
            result = false;
    double  maxX1 = max(getStart()->x(), getEnd()->x()),
            maxY1 = max(getStart()->y(), getEnd()->y()),
            minX1 = min(getStart()->x(), getEnd()->x()),
            minY1 = min(getStart()->y(), getEnd()->y()),

            maxX2 = max( seg->getStart()->x(), seg->getEnd()->x()),
            maxY2 = max( seg->getStart()->y(), seg->getEnd()->y()),
            minX2 = min( seg->getStart()->x(), seg->getEnd()->x()),
            minY2 = min( seg->getStart()->y(), seg->getEnd()->y());

    if(inter->x() <= maxX1 && inter->x() >= minX1)
        x1 = true;
    if(inter->y() <= maxY1 && inter->y() >= minY1)
        y1 = true;
    if(inter->x() <= maxX2 && inter->x() >= minX2)
        x2 = true;
    if(inter->y() <= maxY2 && inter->y() >= minY2)
        y2 = true;
    result = x1 && x2 && y1 && y2;
    if(result)
        return true;
    else
        return false;
}

double Segment::Angle(Segment *seg)
{
    if((this->B * seg->getA() - seg->getB() * this->A) < 0)
        return	acos((this->B * seg->getB() + this->A * seg->getA()) /
                     (sqrt(this->A * this->A + this->B * this->B) *
                     sqrt(seg->getA() * seg->getA() + seg->getB() * seg->getB()))) * 180.0 / PI;
    else
        return	360 - acos((this->B * seg->getB() + this->A * seg->getA()) /
                     (sqrt(this->A * this->A + this->B * this->B) *
                      sqrt(seg->getA() * seg->getA() + seg->getB() * seg->getB()))) * 180.0 / PI;
}

int Segment::test (Segment *seg){
    QString temp;
    int result = 0;//0-не перетинаються, 1-перетинаються, 2-накладаються
    if(equal(seg))
    {
        temp.push_back("Відрізки лежать на одній прямій");
        if (range(seg, this->startPoint) || range(seg, this->endPoint)){
            temp.push_back("\nВідрізки перетинаються");
            result = 1;
            if(this->startPoint->x() == seg->getStart()->x() && this->startPoint->y() == seg->getStart()->y()){
//                temp.push_back("В точці Х = ");
//                temp.push_back(QString::number(this->startPoint->x()));
//                temp.push_back(" Y = ");
//                temp.push_back(QString::number(this->startPoint->y()));
                return result;
            }
            else if(this->startPoint->x() == seg->getEnd()->x() && this->startPoint->y() == seg->getEnd()->y()){
//                temp.push_back("В точці Х = ");
//                temp.push_back(QString::number(this->startPoint->x()));
//                temp.push_back(" Y = ");
//                temp.push_back(QString::number(this->startPoint->y()));
                return result;
            }
            else if(this->endPoint->x() == seg->getStart()->x() && this->endPoint->y() == seg->getStart()->y()){
//                temp.push_back("В точці Х = ");
//                temp.push_back(QString::number(this->endPoint->x()));
//                temp.push_back(" Y = ");
//                temp.push_back(QString::number(this->endPoint->y()));
                return result;
            }
            else if(this->endPoint->x() == seg->getEnd()->x() && this->endPoint->y() == seg->getEnd()->y()){
//                temp.push_back("В точці Х = ");
//                temp.push_back(QString::number(this->endPoint->x()));
//                temp.push_back(" Y = ");
//                temp.push_back(QString::number(this->endPoint->y()));
                return result;
            }
            else{
                //temp.push_back("в безліч точок");
                result = 2;
                return result;
            }
        }
        else{
            //temp.push_back("\nВідрізки не перетинаються");
            result = 0;
            return result;
        }
    }
    if(parallelLines(seg)){
        //temp.push_back("Відрізки паралельні");
        result = 0;
    }
    else
    {
        if(intersect(seg)){
//            temp.push_back("Відрізки перетинаються в точці: Х = ");
//            temp.push_back(QString::number(this->intersectPoint->x()));
//            temp.push_back(" Y = ");
//            temp.push_back(QString::number(this->intersectPoint->y()));
            result = 1;
            return result;
        }
        else{
            //temp.push_back("Відрізки не перетинаються");
            result = 0;
            return result;
        }
    }
//    temp.push_back("\nКут  між прямими: ");
//    temp.push_back(QString::number(Angle(seg)));
    return result;
}
