#include <ncurses.h>

int main(int argc, char **argv)
{
    initscr();
    /* use get out key ctrl + c */
    cbreak();

    //raw();
    /* no intput value show */
    noecho();

    int height, width, start_y, start_x;
    int left, right, top, bottom, tlc, trc, blc, brc;

    left = right = (int)'g';
    top = bottom = (int)'h';
    tlc = trc = blc = brc = (int)'+';
    height = 10;
    width = 20;
    start_y = start_x = 10;

    /* make box size set */
    WINDOW *win = newwin(height, width, start_y, start_x);

    refresh();
    /*box is win, raw, cal style */
    //box(win, 0, 0);
    /* make box another method */
    wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
    mvwprintw(win, 1, 1, "this is my box");
    wrefresh(win);

    getch();
    getch();

    endwin();

    return 0;
}