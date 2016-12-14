#pragma once
#include <vector>
#include "Direction.h"
#include "Point.h"

using namespace std;

class Snake
{
private:
    vector<Point> *body;

public:
    Snake(int x, int y);
    ~Snake();

    vector<Point>* getBody();
};
