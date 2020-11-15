#include <stdio.h>
#include <libintl.h>
#include <locale.h>

 #define tr(STRING) gettext(STRING)

int main()
{
    int s = 1, e = 100;
    char c[100];
    setlocale (LC_ALL, "");
    bindtextdomain ("guess", ".");
    textdomain ("guess");
    printf(tr("Guess a number from 1 to 100\n"));    
    while(s != e)
    {
        printf(tr("Is your number over %d? (y/n)\n"), (s + e) / 2);
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
    printf(tr("Your number is %d\n"), s);
}