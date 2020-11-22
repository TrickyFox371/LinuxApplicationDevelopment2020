#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>
#include "roman.h"

#define HELP tr("Program guess your number from 1 to 100\n\
\n\
Usage: main [OPTIONS]\n\
\n\
       --help    print this help\n\
       --version print programm version\n\
       -r        enter in roman-number mode\n\
\n\
")
#define VERSION "1.0"

/** gettext() wrapper */
#define tr(STRING) gettext(STRING)

/**
 * Convert @p num from Arabic to Roman
 *
 * @param num The number to convert
 *
 * @returns The Roman number equivalent
 *
 */
char *toRoman(int num)
{
    return roman[num - 1];
}

/**
 * Convert @p rom from Roman to Arabic
 *
 * @param rom The number to convert
 *
 * @returns The Arabic number equivalent
 *
 */
int fromRoman(char *rom)
{
    for (int i; i < 100; ++i)
    {
        if (!strcmp(rom, roman[i]))
        {
            return i + 1;
        }
    }
    
    return -1;
}

int main(int argc, char **argv)
{
    int s = 1, e = 100, useRoman = 0;
    char c[100];
    setlocale (LC_ALL, "");
    bindtextdomain ("guess", ".");
    textdomain ("guess");

    if(argc > 1)
    {
        if(!strcmp(argv[1], "-r"))
        {
            useRoman = 1;
        }
        else if (!strcmp(argv[1], "--help"))
        {
            printf("%s\n", HELP);
            return 0;
        }
        else if (!strcmp(argv[1], "--version"))
        {
            printf("%s\n", VERSION);
            return 0;
        }
    }

    if (!useRoman)
    {
        printf(tr("Guess a number from 1 to 100\n"));
    }
    else
    {
        printf(tr("Guess a number from I to C\n"));
    }
    
    while(s != e)
    {
        if (!useRoman)
        {
            printf(tr("Is your number over %d? (y/n)\n"), (s + e) / 2);
        }
        else
        {
            printf(tr("Is your number over %s? (y/n)\n"), toRoman((s + e) / 2));
        }
        scanf("%s", &c);
        if(c[0] == 'y')
        {
            s = (s + e) / 2 + 1;
        }
        else
        {
            if(c[0] == 'n')
            {
                e = (s + e) / 2;
            }
            else
            {
                printf(tr("Incorrect input\n"));
            }
        }
    }

    if (!useRoman)
    {
        printf(tr("Your number is %d\n"), s);
    }
    else
    {
        printf(tr("Your number is %s\n"), toRoman(s));
    }
}