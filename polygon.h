#ifndef POLYGON_H
#define POLYGON_H

#include <point.h>
#include <QVector>
#include <segment.h>

class Polygon
{
private:
    QVector<Point*> coordinates;
    double max_x;
public:
    Polygon();
    Polygon(QVector<Point *> coordinates);
    void setPolygon(QVector<Point*> coordinates);
    void addPoint(Point *point);
    bool isPointInOrOut(Point *point);
};

#endif // POLYGON_H
