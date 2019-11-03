#include <stdio.h>
#include <ncurses.h>
#include "testing.h"

int main(int argc, char **argv)
{

    int ch;
    int x = 2;
    int y = 0;
    int boxX , boxY;
    int yMax, xMax;
    initscr();
    start_color();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    bkgd(COLOR_PAIR(1));
    getmaxyx(stdscr, yMax, xMax);

    refresh();
    
    WINDOW *win = newwin(20, xMax-20, (yMax/2)-10, 10);
    box(win, 0, 0);
    wbkgd(win, COLOR_PAIR(2));
    wrefresh(win);
    //keypad(win, TRUE);
    getmaxyx(win, boxY, boxX);
    ShowMenu(win, boxX, boxY);
    
    Moving(win, y, x, boxY);
    delwin(win);
    endwin();
    return 0;
}