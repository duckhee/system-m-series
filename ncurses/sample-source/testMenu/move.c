#include "move.h"



/* Set window menu */
void ShowMenu(WINDOW *win, int xMax, int yMax)
{

    /* bold add attribute on */
    attron(A_BOLD);
    /* Make Title */
    mvwprintw(win, 0, (xMax-10)/2, "Test Menu");
    /* bold add attribute off */
    attroff(A_BOLD);
    
    /* Make Menu list */
    for(int i = 1; i < (yMax - 1); i++)
    {
        mvwprintw(win, i, 1, "[");
        mvwprintw(win, i, 3, "]");
        mvwprintw(win, i, 5, "Testing ");
        
    }
    /* use setting key pad on menu */
    //keypad(win, TRUE);
}


/* move pointer up */
void MoveUp(WINDOW *win, int yLoc, int yMoveMin)
{
    //wmove(win, yLoc, 2);
    mvwaddch(win, yLoc, 2, ' ');
    yLoc--;
    if(yLoc < 1)
    {
        yLoc = 1;
    }
}

/* move pointer down */
void MoveDown(WINDOW *win, int yLoc, int yMoveMax)
{
    //wmove(win, yLoc, 2);
    mvwaddch(win, yLoc, 2, ' ');
    yLoc++;
    if(yLoc > yMoveMax-2)
    {
        yLoc = yMoveMax-2;
    }
}

/* moving pointer */
int Moving(WINDOW *win, int yLoc, int yMoveMin, int yMoveMax)
{
    int moving = getch();

    switch(moving)
    {
        case KEY_UP:
            MoveUp(win, yLoc, yMoveMin);
            SelectionDisplay(win, yLoc-1);
        break;
        case KEY_DOWN:
            MoveDown(win, yLoc, yMoveMax);
            SelectionDisplay(win, yLoc+1);
        break;
        default:
        break;
    }
    wmove(win, yLoc, 2);
    mvwaddch(win, yLoc, 2, '*');
    wrefresh(win);
    return moving;
}

/* show moving position */
void SelectionDisplay(WINDOW *win, int yLoc)
{
    mvwaddch(win, yLoc, 2, '*');
}

/* exit check menu */
int check_quit()
{
    WINDOW *check;
    int key;
    check = newwin(3, 40, 5, 10);
    wmove(check, 1, 2);
    wprintw(check, "Exit program (y/n) ? "); 
    wbkgd(check, COLOR_PAIR(2));
    box(check, ACS_VLINE, ACS_HLINE);
    refresh();
    key = wgetch(check);
    //werase(check);
    delwin(check);
    if (key == 'y')
    {
        return 1;
    }
    else{
        return 0;
    }
}