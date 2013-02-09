/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 1-8, Chapter1.
 */

#include <stdio.h>

int main(void)
{
    int c, bl, tl, nl;
    bl = 0;
    tl = 0;
    nl = 0;

    printf("Input some characters, then press Ctrl+D.\n");
    while ((c = getchar()) != EOF)
        if (c == ' ')
            ++bl;
        else if (c == '\t')
            ++tl;
        else if (c == '\n')
            ++nl;

    printf("Count of blanks is %d, count of tabs is %d, count of newlines is %d.\n", bl, tl, nl);

    return 0;
}