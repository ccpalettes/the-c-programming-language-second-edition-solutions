/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 4-08, Chapter4.
 */

#include <stdio.h>

int getch(void);
void ungetch(int);

int main(void)
{
    ungetch('a');
    ungetch('t');
    putchar(getch());

    return 0;
}

int buf = -1; /* buffer for ungetch */

int getch(void) /* get a (possibly pushed-back) character */
{
    int b = buf;
    if (b > -1) {
        buf = -1;
        return b;
    }
    return getchar();
}

void ungetch(int c) /* push character back on input */
{
    buf = c;
}