#include <ncurses.h>
#include <stdint.h>
#include <string.h>

int main()
{
    initscr();
    noecho();
    cbreak();


    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *inputwin = newwin(0,xMax-12, yMax-8, 5);
    box(inputwin, 0, 0);
    refresh();
    wrefresh(inputwin);
    /* make it so we can arrow keys */
    keypad(inputwin, true);

    uint8_t *choices[3] = {"walk", "jog", "run"};


    int choice;
    int highlight = 0;

    while(1)
    {
        for(int i = 0; i < 3; i++)
        {
            if( i == highlight)
            {
                wattron(inputwin, A_REVERSE);
            }
            mvwprintw(inputwin, i+1, 1, choices[i]);
            wattroff(inputwin, A_REVERSE);
        }
        choice = wgetch(inputwin);

        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if(highlight == -1)
                {
                    highlight = 0;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == 3)
                {
                    highlight = 2;
                }
                break;
            default:
            break;
        }
        if(choice == 10)
        {
            break;
        }
    }
    printw("your choice is :%s", choices[highlight]);

    getch();
    endwin();
    return 0;
}