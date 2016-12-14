#pragma once

class Point
{
private:
    void init(int x = 0, int y = 0);

public:
    Point(int x = 0, int y = 0);
    Point(Point* p);
    ~Point();
    int x;
    int y;
};
