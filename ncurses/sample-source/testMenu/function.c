#include "function.h"

/* Menu value */
extern int yMaxMenu, xMaxMenu;
extern int yLoc = 1;
extern WINDOW *win;


/* Set window menu */
void ShowMenu()
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
void MoveUp()
{
    wmove(win, yLoc, 2);
    mvwaddch(win, yLoc, 2, ' ');
    yLoc-= 1;
    if(yLoc < 1)
    {
        yLoc = 1;
    }
}

/* move pointer down */
void MoveDown()
{
    wmove(win, yLoc, 2);
    mvwaddch(win, yLoc, 2, ' ');
    yLoc += 1;
    if(yLoc > yMoveMax-2)
    {
        yLoc = yMoveMax-2;
    }
}

/* moving pointer */
int Moving()
{
    int moving = getch();

    switch(moving)
    {
        case KEY_UP:

            MoveUp();
            
        break;
        case KEY_DOWN:
            MoveDown();
            
        break;
        default:
        break;
    }
    return moving;
}

/* show moving position */
void SelectionDisplay()
{
    mvwaddch(win, yLoc, 2, '*');
}
