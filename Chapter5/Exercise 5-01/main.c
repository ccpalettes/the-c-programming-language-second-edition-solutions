/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-01, Chapter5.
 */

#include <stdio.h>
#include <ctype.h>
#include "getch.h"

#define SIZE 10

int getint(int *);

int main(void)
{
    int n, array[SIZE], r;

    for (n = 0; n < SIZE && (r = getint(&array[n])) != EOF; n++) {
        if (r)
            printf("you input a number: %d\n", array[n]);
        else
            printf("it is not a number.\n");
    }

    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign, c2;

    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        if (!isdigit(c2 = getch())) {
            ungetch(c2);
            ungetch(c);
            return 0;
        } else
            c = c2;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}