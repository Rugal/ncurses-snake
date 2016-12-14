#include <vector>
#include "Direction.h"
#include "Point.h"
#include "Snake.h"

vector<Point>* Snake::getBody()
{
    return this->body;
}

Snake::Snake(int x, int y)
{
    body = new vector<Point>();
    body->push_back(new Point(x, y));
}

Snake::~Snake()
{
    delete body;
}
