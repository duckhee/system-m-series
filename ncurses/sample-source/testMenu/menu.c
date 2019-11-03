#include <ncurses.h>
#include <stdint.h>
//#include "move.h"
//#include "function.h"


//uint8_t commandList[] = {"test", "test","test","test","test","test","test"};




/* init set back ground and default setting */
void init_curses()
{

    /* initializes the screen */
    initscr();
    /* color attribute setting */
    start_color();
    /* color setting */
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3, COLOR_RED, COLOR_WHITE);
    /* 설정하며 0~2사이의 인자값을 가진다. 0에 가까울수록 커서가 안보인다. */
    curs_set(1);
    /* background color setting */
    bkgd(COLOR_PAIR(1));
    /* noecho mode setting */
    noecho();
    /* line buffer setting */
    //raw();
    /* key up, down, left, right, etc use setting */
    keypad(stdscr, TRUE);

}

/* create box and return WINDOW */
WINDOW *createMain(int height, int width, int startY, int startX)
{
    /* Make window Setting */
    WINDOW *local_win = newwin(height, width, startY, startX);
    box(local_win, 0, 0);
    /* setting box background setting */
    wbkgd(local_win, COLOR_PAIR(2));
    wrefresh(local_win);
    /* return pointer */
    return local_win;
}


/* Set window menu */
void ShowMenu(WINDOW *win, int xMax, int yMax)
{

    /* bold add attribute on */
    attron(A_BOLD);
    /* Make Title */
    mvwprintw(win, 0, (xMax-10)/2, "Test Menu");
    /* bold add attribute off */
    attroff(A_BOLD);
    
    /* Make Menu list */
    for(int i = 1; i < (yMax - 1); i++)
    {
        mvwprintw(win, i, 1, "[");
        mvwprintw(win, i, 3, "]");
        mvwprintw(win, i, 5, "Testing ");
        
    }
    wmove(win, 1, 2);
    wrefresh(win);
    /* use setting key pad on menu */
    //keypad(win, TRUE);
}

/* move pointer up */
void MoveUp(WINDOW *win, int yLoc, int xLoc, int yMoveMin)
{
    mvwaddch(win, yLoc, xLoc, ' ');
    yLoc--;
    if(yLoc < yMoveMin)
    {
        yLoc = yMoveMin;
    }
}

/* move pointer down */
void MoveDown(WINDOW *win, int yLoc, int xLoc, int yMoveMax)
{
    mvwaddch(win, yLoc, xLoc, ' ');
    yLoc++;
    if(yLoc > yMoveMax - 2)
    {
        yLoc = yMoveMax - 2;
    }
}

/* moving pointer */
void Moving(WINDOW *win, int yLoc, int xLoc, int yMoveMin, int yMoveMax)
{
    int ch;
    while((ch = getch() != 'q'))
    {
        switch(ch)
        {
            case KEY_UP:
                //MoveUp(win, yLoc, xLoc, 1);
                if(yLoc != 0)
                    mvwaddch(win, yLoc, xLoc, ' ');
                yLoc--;
                if(yLoc < 1)
                {
                    yLoc = 1;
                }
            break;
            case KEY_DOWN:
                //MoveDown(win, yLoc, xLoc, yMoveMax);
                if(yLoc != 0)
                    mvwaddch(win, yLoc, xLoc, ' ');
                yLoc++;
                if(yLoc > yMoveMax - 2)
                {
                    yLoc = yMoveMax - 2;
                }
            break;
            default:
            break;
        }
        wmove(win, yLoc, xLoc);
        mvwaddch(win, yLoc, xLoc, '*');
        wrefresh(win);
    }
}



int main(int argc, char **argv)
{
    /* get Window value */
    int yMax, xMax;
    /* Menu value */
    int yMaxMenu, xMaxMenu;
    int yLoc = 0;
    int xLoc = 2;
    /* main window pointer */
    WINDOW *win;
    
    init_curses();
    /* get max size yMax, xMax */
    getmaxyx(stdscr, yMax, xMax);
    refresh();
    /* make new window start end y point, end x point, start y point, start x point */
    //win = newwin(20, (xMax)-20, (yMax/2)-10, 10);
    win = createMain(20, (xMax)-20, (yMax/2)-10, 10);
    /* key up, down, left, right, etc use setting */
    //keypad(stdscr, TRUE);

    /* Make box */
    //box(win, 0, 0);
    
    /* setting box background setting */
    wbkgd(win, COLOR_PAIR(2));
    refresh();
    /* get max box menu size */
    getmaxyx(win, yMaxMenu, xMaxMenu);
    /* show menu list */
    ShowMenu(win, xMaxMenu, yMaxMenu);
    wmove(win, 1, 2);
    mvwaddch(win, 1, 2, '*');
    /* refresh window */
    wrefresh(win);
    /* show select */
    Moving(win, yLoc, xLoc, 1, yMaxMenu);
    /* refresh the screen to match whats is memory */
    refresh();
    delwin(win);
    endwin();

    return 0;
}