#include <iostream>
#include <ncurses.h>
#include "Point.h"


using namespace std;

int main(int argc, char *argv[])
{
    Point* p = new Point(1, 2);
    delete p;
    return 0;
}
