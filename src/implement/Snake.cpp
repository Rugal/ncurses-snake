#include <list>
#include <assert.h>
#include <stdbool.h>
#include <ncurses.h>
#include "Point.h"
#include "Snake.h"

using namespace std;

static bool collide(Point* first, Point* second)
{
    return first->x == second->x
        && first->y == second->y;
}

Snake::Snake(int x, int y)
{
    body = new list<Point>();
    body->push_back(new Point(x, y));
    this->direction = KEY_RIGHT;
}

Snake::~Snake()
{
    delete body;
}

list<Point>::iterator Snake::begin()
{
    return this->body->begin();
}

list<Point>::iterator Snake::end()
{
    return this->body->end();
}

Point& Snake::back()
{
    return this->body->back();
}

Point& Snake::front()
{
    return this->body->front();
}

int Snake::size()
{
    return this->body->size();
}

bool Snake::move(Point* food)
{
    list<Point>::iterator head = this->body->begin();
    switch(this->direction)
    {
        case KEY_UP:
            this->body->push_front(new Point(head->x-1, head->y));
            break;
        case KEY_DOWN:
            this->body->push_front(new Point(head->x+1, head->y));
            break;
        case KEY_LEFT:
            this->body->push_front(new Point(head->x, head->y-1));
            break;
        case KEY_RIGHT:
            this->body->push_front(new Point(head->x, head->y+1));
            break;
    }
    bool eat = collide(&(this->body->front()), food);
    if(!eat)
        this->body->pop_back();
    return eat;
}
