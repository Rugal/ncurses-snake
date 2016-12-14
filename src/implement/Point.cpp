#include "Point.h"

void Point::init(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::Point(int x, int y)
{
    init(x, y);
}

Point::Point(Point* p)
{
    init(p->x, p->y);
}

Point::~Point(){}
