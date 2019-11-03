#ifndef __PLAYER_H__
#define __PLAYER_H__



class Player
{
    public:
        Player(WINDOW *win, int y, int x, char c);

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        int getMove();
        void display();
    private:
        int xLoc, yLoc, xMax, yMax;
        char character;
        WINDOW *curwin;
};

Player::Player(WINDOW *win, int y, int x, char c)
{
    curwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
}

void Player::moveUp()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc--;
    if(yLoc < 1)
    {
        yLoc = 1;
    }
}

void Player::moveDown()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc++;
    if(yLoc > yMax-2)
    {
        yLoc = (yMax-2);
    }
}

void Player::moveLeft()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc--;
    if(xLoc < 1)
    {
        xLoc = 1;
    }
}

void Player::moveRight()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc++;
    if(xLoc > xMax -2)
    {
        xLoc = (xMax-2);
    }
}

int Player::getMove()
{
    int choice = wgetch(curwin);
    switch(choice)
    {
        case KEY_UP:
            moveUp();
        break;
        case KEY_DOWN:
            moveDown();
        break;
        case KEY_LEFT:
            moveLeft();
        break;
        case KEY_RIGHT:
            moveRight();
        break;
        default:
        break;
    }
    return choice;
}

void Player::display()
{
    /**/
    mvwaddch(curwin, yLoc, xLoc, character);
}

#endif