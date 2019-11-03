/**
 * File Name : MakeWindow.c
 * Auther    : Doukhee Won
 * Version   : V1.0
 * Date      : 2019/10/16
 */

#include "MakeWindow.h"
#include <string.h>


/* init setting ncurses do first */
void InitMain(bool EchoFlag)
{
    initscr();
    start_color();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    //raw();
    if(EchoFlag)
    {
        noecho();
    }
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3, COLOR_BLUE, COLOR_WHITE);
    bkgd(COLOR_PAIR(1));
    refresh();
}

/* make main menu box */
WINDOW *CreateMain(int height, int weight, int startY, int startX)
{
    WINDOW *win = newwin(height, weight, startY, startX);
    /* make box */
    box(win, 0, 0);
    /* setting box background */
    wbkgd(win, COLOR_PAIR(2));
    /* return window pointer */
    return win;
}

//TODO
/* show menu list */
void ShowMenu(WINDOW *win, int xMax, char **list, int startList, int endList)
 {
    /* setting bold attribute */
    wattron(win, A_BOLD);
    mvwprintw(win, 0, xMax/2-5, "Main Menu");
    wattroff(win, A_BOLD);
    /* show menu list */
    for(int i = startList; i < endList; i++)
    {
        mvwprintw(win, i+1, 1, "[");
        mvwprintw(win, i+1, 3, "]");
        mvwprintw(win, i+1, 5, "%s", *list++);
    }
    wmove(win, 1, 2);
    wrefresh(win);
}

/* show menu list */
void TestShowMenu(WINDOW *win, int xMax, int yMax)
{
    /* setting bold attribute */
    attron(A_BOLD);
    mvwprintw(win, 0, xMax/2-5, "Main Menu");
    attroff(A_BOLD);
    
    /* show menu list */
    for(int i = 0; i < yMax-2; i++)
    {
        mvwprintw(win, i+1, 1, "[");
        mvwprintw(win, i+1, 3, "]");
        mvwprintw(win, i+1, 5, "Testing");
    }
    wmove(win, 1, 2);
    wrefresh(win);
}

//TODO
/* select menu */
int Select(WINDOW *win, int x, int y, int yMax)
{
    /* return select menu number */
    int ch;
    /* exit q key */
    while(1)
    {
        /* default first select list 1 */
        if(y == 1)
        {
            /* move win pointer y, x */
            mvwaddch(win, y, x, '*');
            /* refresh win */
            wrefresh(win);
        }
        /* get move value */
        ch = getch();
        /* move up down */
        switch(ch)
        {
            case KEY_UP:
                if(y != 0)
                    mvwaddch(win, y, x, ' ');
                y--;
                if(y < 1)
                    y = 1;
            break;
            case KEY_DOWN:
                if(y != 0)
                    mvwaddch(win, y, x, ' ');
                y++;
                if(y > yMax - 2)
                    y = yMax-2;
            break;
            default:
            break;
        }
        /* show moving pointer */
        if(y != 0)
        {
            wmove(win, y, x);
            mvwaddch(win, y, x, '*');
            wrefresh(win);
        }
        /* exit code */
        if(ch == 'q')
        {
            break;
        }
        /* enter press return y value */
        if(ch == '\n')
        {
            ch = y;
            break;
        }
    }
    return ch;
}

//TODO
/* select menu system do show */
void SelectSystemMenu(int flag, int length)
{

}