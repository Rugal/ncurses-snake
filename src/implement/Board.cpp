#include <list>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Board.h"
#include "Point.h"
#include "Snake.h"
#define MAX_DELAY 100

using namespace std;

static void paintBorder(WINDOW* w)
{
    wborder(w, '|', '|', '-', '-', '+', '+', '+', '+');
}

Board::Board(WINDOW* w)
{
    this->w = w;
    this->clear();
}

Board::~Board()
{
    delete food;
    delete snake;
}

void Board::clearSnake()
{
    for(list<Point>::iterator it=this->snake->begin();
            it!=this->snake->end();
            it++)
        mvprintw(it->x, it->y, " ");
}

void Board::repaintSnake()
{
    this->clearSnake();
    this->paintSnake();
}

void Board::paintSnake()
{
    for(list<Point>::iterator it=this->snake->begin();
            it!=this->snake->end();
            it++)
        mvprintw(it->x, it->y, "*");
}


void Board::repaint(bool eat)
{
    paintBorder(this->w);
    this->paintSnake();
    if(eat)
        this->putFood();
    refresh();
}

void Board::paintFood()
{
    mvprintw(this->food->x, this->food->y, "@");
}

void Board::repaintFood()
{
    this->clearFood();
    this->paintFood();
}

void Board::clearFood()
{
    mvprintw(this->food->x, this->food->y, " ");
}

void Board::clear()
{
    getmaxyx(this->w, this->height, this->width);
    delete this->food;
    delete this->snake;
    this->snake = new Snake(this->height/2, this->width/2);
}

Point* Board::findAvailablePoint()
{
    srand(time(NULL));
    return new Point(rand()%(this->height-1)+1, rand()%(this->width-1)+1);
}

void Board::putFood()
{
    this->clearFood();
    delete this->food;
    this->food = this->findAvailablePoint();
    this->paintFood();
}

void Board::start()
{
    this->food = this->findAvailablePoint();
    this->paintFood();
    int input=KEY_RIGHT;
    do
    {
        int speed = MAX_DELAY - this->snake->size();
        timeout(speed >= 0? speed : 0);
        input = getch();
        Point head = this->snake->front();
        switch(input)
        {
            case KEY_UP:
                this->snake->direction = KEY_UP;
                if(head.x-1<0)
                    input='q';
                break;
            case KEY_DOWN:
                this->snake->direction = KEY_DOWN;
                if(head.x+1 >= this->height)
                    input='q';
                break;
            case KEY_LEFT:
                this->snake->direction = KEY_LEFT;
                if(head.y-1 < 0)
                    input='q';
                break;
            case KEY_RIGHT:
                this->snake->direction = KEY_RIGHT;
                if(head.y+1 >= this->width)
                    input='q';
                break;
            case 'q':
                break;
        }
        this->clearSnake();
        bool eat = this->snake->move(this->food);
        this->repaint(eat);
    }while(input != 'q');
    printw("Your score is %d", this->snake->size());
    this->clearFood();
    this->clearSnake();
}
