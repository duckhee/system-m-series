#include <ncurses.h>

int main(int argc, char **argv)
{   
    /* initializes the screen */
    initscr();
    /* prints a string(const char *) to a window */
    printw("Hello world!");
    /* refreshes the screen to match whats in memory */
    refresh();

    int c = getch();

    printw("%d", c);

    getch();
    /* deallocates memory and ends ncurses */
    endwin();

    return 0;
}