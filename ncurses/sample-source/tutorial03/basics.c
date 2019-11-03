#include <ncurses.h>



int main(int argc, char **argv)
{
    /* initializes the screen */
    /* sets up memory and clear the screen */
    initscr();
    int height, width, start_y, start_x;

    height = 10;
    width = 20;
    start_y = start_x = 10;

    WINDOW *win = newwin(height, width, start_y, start_x);
    
    /* refreshes the screen to match whats in memory */
    refresh();
    /* make box position set */
    box(win, 0, 0);
    /* input box title */
    wprintw(win, "this is teh box");
    /* move input box show title */
    //mvwprintw(win, 1, 1, "this is teh box");
    /* show box */
    wrefresh(win);

    int c = getch();

    endwin();

    return 0;
}