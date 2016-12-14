#include "Food.h"
#include "Point.h"

Food::Food(Point* p)
{
    this->p = p;
}

Food::~Food()
{
    delete p;
}
