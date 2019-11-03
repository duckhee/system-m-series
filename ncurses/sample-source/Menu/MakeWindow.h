/**
 * File Name : MakeWindow.h
 * Auther    : Doukhee Won
 * Version   : V1.0
 * Date      : 2019/10/16
 */

#ifndef __MAKEWINDOW_H__
#define __MAKEWINDOW_H__

/* file include */
#include "menu.h"




/* main menu function */
void InitMain(bool EchoFlag);
WINDOW *CreateMain(int height, int weight, int startY, int startX);
void TestShowMenu(WINDOW *win, int xMax, int yMax);
//TODO
int Select(WINDOW *win, int x, int y, int yMax);
//TODO
void ShowMenu(WINDOW *win, int xMax, char **list, int startList, int endList);
//TODO
void SelectSystemMenu(int flag, int listLength);


#endif