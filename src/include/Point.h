#pragma once

class Point
{
private:
    int x;
    int y;
    void init(int x = 0, int y = 0);

public:
    Point(int x = 0, int y = 0);
    Point(Point* p);
    ~Point();
};
