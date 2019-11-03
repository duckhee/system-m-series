#include <ncurses.h>

int main(int argc, char **argv)
{   
    /* initializes the screen */
    initscr();

    int x, y;
    x = y = 10;

    /* moves the cursor to the specified location */
    move(y, x);

    /* prints a string(const char *) to a window */
    printw("Hello world!");
    /* refreshes the screen to match whats in memory */
    refresh();

    int c = getch();
    /* clears the screen */
    clear();
    refresh();
    
    move(0, 0);
    printw("%d", c);
    refresh();

    /* move print show x, y*/
    //mvprintw(10, 10, "%d", c);


    getch();
    /* deallocates memory and ends ncurses */
    endwin();

    return 0;
}