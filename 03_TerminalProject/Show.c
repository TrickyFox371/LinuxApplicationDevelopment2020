#include <ncurses.h>
#include <stdio.h>
#include <string.h>

#define ESC 27

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Error: Wrong number of arguments\n");
        return 0;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Error: Can not open file\n");
        return 0;
    }
    initscr();
    noecho();
    char *ret = argv[1];
    while (ret != NULL)
    {
        erase();
        addstr("File: ");
        addstr(argv[1]);
        addstr("\n\n");
        int i = 3;
        char str[COLS];
        while ((ret = fgets(str, COLS, f)) != NULL && i < LINES - 1)
        {
            addstr(str);
            ++i;
        }
        if (ret != NULL)
        {
            addstr(str);
        }
        int inp;
        while ((inp = getch()) != ' ' && inp != ESC) { }
        if (inp == ESC)
        {
            endwin();
            return 0;
        }
    }
    int inp;
    while ((inp = getch()) != ESC) { }
    endwin();
    return 0;
}
