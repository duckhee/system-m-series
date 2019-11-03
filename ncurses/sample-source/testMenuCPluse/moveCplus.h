#ifndef __MOVECPLUSE_H__
#define __MOVECPLUSE_H__

class Menu{
    public:
        Menu(WINDOW *win, int y, int x);
        void ShowMenu();
        void MoveUp();
        void MoveDown();
        int Moving();
        void SelectionDisplay();
    private:
        int xLoc, yLoc, xMax, yMax;
        char value;
        WINDOW *curwin;
};


Menu::Menu(WINDOW *win, int y, int x)
{
    curwin = win;
    yLoc = y;
    xLoc = x;
    value = '*';
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);

}

void Menu::ShowMenu()
{
    /* bold add attribute on */
    attron(A_BOLD);
    /* Make Title */
    mvwprintw(curwin, 0, (xMax-10)/2, "Test Menu");
    /* bold add attribute off */
    attroff(A_BOLD);

    /* Make Menu list */
    for(int i = 1; i < yMax-1; i++)
    {
        mvwprintw(curwin, i, 1, "[");
        mvwprintw(curwin, i, 3, "]");
        mvwprintw(curwin, i, 5, "Testing ");
    }
    
}

void Menu::MoveUp()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc--;
    if(yLoc < 1)
    {
        yLoc = 1;
    }
}

void Menu::MoveDown()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc++;
    if(yLoc > yMax - 2)
    {
        yLoc = (yMax - 2);
    }
}

int Menu::Moving()
{
    int choice = wgetch(curwin);
    switch (choice)
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
    return choice;
}

void Menu::SelectionDisplay()
{
    mvwaddch(curwin, yLoc, xLoc, '*');
}

#endif