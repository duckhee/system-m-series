#ifndef __MENU_H__
#define __MENU_H__

#include <stdint.h>
#include <ncurses.h>
#include "MakeWindow.h"
/* menu custom menu header here. */
#include "SelectOS.h"
#include "SelectChapter.h"
#include "MakeWindow.h"


static char **MenuList[] = {
    "select board",
    "select os",
    "select chapter"
      };

#endif