#include <ncurses.h>


void start_ncurses(bool, bool);


void start_ncurses(bool Raw, bool Noecho)
{
    initscr();
    if(Raw)
    {
        raw();
    }
    if(Noecho)
    {
        noecho();
    }
}


int main(int argc, char **argv)
{
    initscr();
    noecho();
    cbreak();

    int y, x, xBeg, yBeg, xMax, yMax;
    
    /* make window */
    WINDOW *win = newwin(10, 20, 10, 10);
    /**/
    getyx(stdscr, y, x);
    /**/
    //getbegyx(stdscr, xBeg, yBeg);
    getbegyx(win, xBeg, yBeg);
    /* get terminal max raw, col */
    getmaxyx(stdscr, yMax, xMax);
    /* x size, y size move and show */
    //mvprintw(yMax/2, xMax/2, "Hello");
    mvprintw(yMax/2, xMax/2, "%d %d", yBeg, xBeg);
    
    //refresh();

    //printw("%d %d %d %d %d %d", y, x, xBeg, yBeg, xMax, yMax);


    getch();

    endwin();

    return 0;
}