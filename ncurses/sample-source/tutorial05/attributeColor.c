#include <ncurses.h>

void start_ncurses(bool, bool);


int main(int argc, char **argv)
{
    /* NCURSES START */
    start_ncurses(true, true);
    /* initializes the screen */
    //initscr();

    if(!has_colors())
    {
        printw("Terminal does not support color");
        getch();
        return -1;
    }
    /* ncurses에 색 attribute를 사용한다고 설정 */
    start_color();
    /* color option set text style, background style */
    init_pair(1, COLOR_CYAN, COLOR_WHITE);
    init_pair(2, COLOR_YELLOW, COLOR_MAGENTA);
    /**/
    if(can_change_color())
    {
        printw("can change color");
        init_color(COLOR_CYAN, 9, 999, 999);
    }
    /**
     * A_NORMAL
     * A_STANDOUT
     * A_REVERSE
     * A_BLINK
     * A_DIM
     * A_BOLD
     * A_PROTECT
     * A_INVIS
     * A_ALTCHARSET
     * A_CHARTEXT
     */
    
    /* attribute 적용 */
    //attron(A_REVERSE);
    attron(COLOR_PAIR(1));
    printw("This is some text");
    /* attribute 제거 */
    //attroff(A_REVERSE);
    attroff(COLOR_PAIR(1));

    /**
     * COLOR_PAIR(n)
     * COLOR_BLACK      0
     * COLOR_RED        1
     * COLOR_GREEN      2
     * COLOR_YELLOW     3
     * COLOR_BLUE       4
     * COLOR_MAGENTA    5
     * COLOR_CYAN       6
     * COLOR_WHITE      7
     */

    getch();

    endwin();
    return 0;
}

void start_ncurses(bool useRaw, bool useNoecho)
{
    initscr();
    if(useRaw)
    {
        raw();
    }
    if(useNoecho){
        noecho();
    }
}