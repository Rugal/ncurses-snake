#include <ncurses.h>
#include "Board.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define INITIALIZE() \
    do {\
        initscr();\
        cbreak();\
        noecho();\
        keypad(stdscr, TRUE);\
        curs_set(0);\
        wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');\
    }while(0)\

#define CLEAN() \
    do{ \
        endwin();\
    }while(0)\

int main(int argc, char *argv[])
{
    INITIALIZE();

    Board* b = new Board(stdscr);

    int input;
    do
    {
        timeout(-1);
        input = getch();
        switch(input)
        {
            case 10:
                b->clear();
                b->start();
                break;
            case 27:
                input = 'q';
                break;
        }
    }while(input!='q');

    delete b;
    CLEAN();
    return 0;
}
