/**
 * File Name : menu.c
 * Auther    : Doukhee Won
 * Version   : V1.0
 * Date      : 2019/10/16
 */


#include "menu.h"


int main(int argc, char **argv)
{
    /* get terminal size */
    int TSizeY, TSizeX;
    /* get menu box size */
    int BSizeY, BSizeX;
    /* get borad box value */
    int BoardSizeY, BoardSizeX;
    /* move point value */
    int yLoc = 1;

    /* get main menu box pointer */
    WINDOW *MainMenu;
    WINDOW *OutMenuSet;

    InitMain(TRUE);
    /* get terminal size */
    getmaxyx(stdscr, TSizeY, TSizeX);

    /* create main menu box */
    MainMenu = CreateMain(TSizeY-10, TSizeX-10, 5, 5);

    /* get menu box size */
    getmaxyx(MainMenu, BSizeY, BSizeX);

    /* Question set box */
    OutMenuSet = CreateMain(TSizeY-6, TSizeX-6, 3, 3);

    /* Get Menu Board Size */
    getmaxyx(OutMenuSet, BoardSizeY, BoardSizeX);
    /* bold setting */
    wattron(OutMenuSet, A_BOLD);
    wattron(OutMenuSet, COLOR_PAIR(3));
    mvwprintw(OutMenuSet, 0, BoardSizeX/2-10, "Select Menu List");
    /* bold setting off */
    wattroff(OutMenuSet, A_BOLD);
    wattroff(OutMenuSet, COLOR_PAIR(3));
    /* show box */
    wrefresh(OutMenuSet);
    /* select menu list show */
    wrefresh(MainMenu);

    /* show menu */
    ShowMenu(MainMenu, BSizeX, MenuList, 0, 3);
    //TestShowMenu(MainMenu, BSizeX, BSizeY);

    /* select menu max list length + 2 */
    int menuFlag = Select(MainMenu, 2, yLoc, 5);

    /* check select '\n' */
    if(menuFlag != 'q')
    {
        /* delete Main menu box */
        werase(MainMenu);
        wprintw(MainMenu, "Enter DO %d", menuFlag);
        
        wprintw(MainMenu, "%d", A_BOLD);
        wrefresh(MainMenu);
        refresh();
        /* delay input */
        getch();
    }

    /* delete main menu box */
    delwin(MainMenu);
    /* close ncurses */
    endwin();

    return 0;
}

