#include <ncurses.h>


int main(int argc, char **argv)
{
    initscr();

    WINDOW *win = newwin(10, 30, 0, 0);
    box(win, 0, 0);
    refresh();
    /* 특정 윈도우를 고치는 함수 */
    wrefresh(win);
    /* input window */
    wgetch(win);

    getch();
    endwin();

    return 0;
}