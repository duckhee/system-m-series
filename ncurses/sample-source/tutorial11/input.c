#include <ncurses.h>

int main(int argc, char **argv)
{
    initscr();
    noecho();

    /* INPUT MODES */
    //cbreak();
    /* delay The value of tenths must be a number between 1 and 255.  */
    //halfdelay(5);
    /* no delay setting */
    //nodelay(stdscr, true);
    /**/
    //timeout(-1);

    int c;

    while((c = getch()) != 'x')
    {
        printw("%d\n", c);
    }

    endwin();


    return 0;


}