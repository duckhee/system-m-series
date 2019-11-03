#ifndef __MOVE_H__
#define __MOVE_H__

#include <ncurses.h>

typedef struct
{
    WINDOW *curwin;
    int xLoc;
    int yLoc;
    int xMax;
    int yMax;
}MenuInitTypeDef;


void ShowMenu(WINDOW *win, int xMax, int yMax);
void MoveUp(WINDOW *win, int yLoc, int yMoveMin);
void MoveDown(WINDOW *win, int yLoc, int yMoveMax);
int Moving(WINDOW *win, int yLoc, int yMoveMin, int yMoveMax);
void SelectionDisplay(WINDOW *win, int yLoc);




#endif