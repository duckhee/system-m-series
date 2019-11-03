#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"


int main(int argc, char **argv)
{
    initscr();
    noecho();
    cbreak();

    int yMax, xMax, xMaxBox, yMaxBox;
    int xLoc = 1;
    int yLoc = 1;
    char c = '*';
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *playwin = newwin(20, 50, (yMax/2)-10, 10);
    box(playwin, 0, 0);
    refresh();
    wrefresh(playwin);

    getmaxyx(playwin, yMaxBox, xMaxBox);

    Player *p = new Player(playwin, 1, 1, '@');

    do
    {
        p->display();
        wrefresh(playwin);
    }while(p->getMove()!='x');

    //getch();
    endwin();
    return 0;
}
