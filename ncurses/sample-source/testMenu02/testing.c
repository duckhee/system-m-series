
#include "testing.h"



void ShowMenu(WINDOW *win, int boxX, int boxY)
{
    /* bold add attribute on */
    attron(A_BOLD);
    /* Make Title */
    mvwprintw(win, 0, (boxX-10)/2, "Test Menu");
    /* bold add attribute off */
    attroff(A_BOLD);
    
    /* Make Menu list */
    for(int i = 1; i < boxY-1; i++)
    {
        mvwprintw(win, i, 1, "[");
        mvwprintw(win, i, 3, "]");
        mvwprintw(win, i, 5, "Testing ");
        
    }
    wmove(win, 1, 2);
    wrefresh(win);
}

void Moving(WINDOW *win, y, x, boxY)
{
    int ch;
    while((ch = getch()) != 'q')
    {
        switch(ch)
        {
            case KEY_UP:
                if(y != 0)
                    mvwaddch(win, y, x, ' ');
                y--;
               if(y <  1)
               {
                   y = 1;
               }
            break;
            case KEY_DOWN:
                if(y != 0)
                    mvwaddch(win, y, x, ' ');
                y++;
                if(y > boxY - 2)
                {
                    y = boxY-2;
                }
            break;
        }
        wmove(win, y, x);
        mvwaddch(win, y, x, '*');
        wrefresh(win);
    }
}