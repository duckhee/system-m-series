#include <ncurses.h>
//#include <string.h>


void start_ncurses(bool useRaw, bool useNoecho);
//void printMenu(WINDOW *menu, String choice[], int size, int highlight);

int main(int argc, char **argv)
{
    initscr();
    noecho();
    cbreak();


    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *inputwin = newwin(3, xMax-12, yMax-5, 5);
    box(inputwin, 0, 0);
    refresh();
    wrefresh(inputwin);

    /* setting keypad use */
    keypad(inputwin, true);

    /* get window capture input value */
    int c = wgetch(inputwin);
    //if(c == 'j')
    if(c == KEY_UP)
    {
         mvwprintw(inputwin, 1, 1, "you pressed j!!");
         wrefresh(inputwin);
    }
    getch();
    endwin();

    return 0;
}