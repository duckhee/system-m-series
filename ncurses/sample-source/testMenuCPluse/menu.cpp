#include <ncurses.h>
#include <stdint.h>
//#include "move.h"
#include "moveCplus.h"

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
    //keypad(stdscr, TRUE);

}

int main(int argc, char **argv)
{
    /* get Window value */
    int yMax, xMax;

    /* Menu value */
    int yMaxMenu, xMaxMenu;
    int *yLocP ;
    int yLoc = 1;

    init_curses();
    /* get max size yMax, xMax */
    getmaxyx(stdscr, yMax, xMax);
    /* make new window start end y point, end x point, start y point, start x point */
    WINDOW *win = newwin(20, (xMax)-20, (yMax/2)-10, 10);
    /* key up, down, left, right, etc use setting */
    keypad(win, TRUE);
    /* get max box menu size */
    getmaxyx(win, yMaxMenu, xMaxMenu);

    /* Make box */
    box(win, 0, 0);
    
    /* setting box background setting */
    wbkgd(win, COLOR_PAIR(2));
    refresh();
    
    /**/
    Menu *menu = new Menu(win, 1, 2);
    menu->ShowMenu();
    //ShowMenu(win, xMaxMenu, yMaxMenu);
    // /* refresh window */
    wrefresh(win);

    /* show select */

    do
    {
        menu->SelectionDisplay();
        wrefresh(win);
    }while(menu->Moving() != 'x');

    /*
    while(1){
        int flag = Moving(win, yLoc, 1, yMaxMenu);
        SelectionDisplay(win, yLoc);
        refresh();
        wrefresh(win);
        
        if(flag == 'x')
        {
            break;
        }
    }
    */

    /* refresh the screen to match whats is memory */
    refresh();
    delwin(win);
    endwin();

    return 0;
}