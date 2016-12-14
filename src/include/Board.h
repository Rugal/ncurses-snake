#pragma once
#include <ncurses.h>
#include <stdbool.h>
#include "Point.h"
#include "Snake.h"

class Board
{
private:
    int width;
    int height;
    WINDOW* w;
    Point* food;
    Snake* snake;

    void repaint(bool eat);
    //
    void repaintSnake();
    void clearSnake();
    void paintSnake();
    //
    void repaintFood();
    void clearFood();
    void paintFood();
    //
    Point* findAvailablePoint();
    void putFood();

public:
    Board(WINDOW* w);
    ~Board();

    void clear();
    void start();
};
