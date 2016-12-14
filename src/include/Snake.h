#pragma once
#include <list>
#include <stdbool.h>
#include "Point.h"

using namespace std;

class Snake
{
private:
    list<Point> *body;

public:
    int direction;

    Snake(int x, int y);
    ~Snake();

    bool move(Point* food);
    list<Point>::iterator begin();
    list<Point>::iterator end();
    Point& back();
    Point& front();
    int size();
};
