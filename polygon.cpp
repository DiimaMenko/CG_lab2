#include "polygon.h"
#include <QtMath>

Polygon::Polygon()
{

}

Polygon::Polygon(QVector<Point *> coordinates){
    this->coordinates = coordinates;
    this->max_x = this->coordinates[0]->x();
    for(int i = 0; i < this->coordinates.size(); i++){
        if(coordinates[i]->x() > this->max_x){
            this->max_x = coordinates[i]->x();
        }
    }
}

void Polygon::setPolygon(QVector<Point *> coordinates){
    this->coordinates.resize(0);
    this->coordinates = coordinates;
}

void Polygon::addPoint(Point *point){
    this->coordinates.push_back(point);
}

bool Polygon::isPointInOrOut(Point *point){
    int crossCounter = 0;
    Segment *mainSegment = new Segment(point->x(), point->y(), this->max_x + 1.0, point->y());
    Segment *currentSegment = new Segment(this->coordinates[0], this->coordinates[1]);
    crossCounter += mainSegment->test(currentSegment);
    for(int i = 2; i < this->coordinates.size(); i++){
        currentSegment->setSegment(currentSegment->getEnd(), this->coordinates[i]);
        crossCounter += mainSegment->test(currentSegment);
    }
    currentSegment->setSegment(currentSegment->getEnd(), this->coordinates[0]);
    crossCounter += mainSegment->test(currentSegment);
    if(crossCounter % 2 == 0){
        return false;
    }
    else{
        return true;
    }
}
