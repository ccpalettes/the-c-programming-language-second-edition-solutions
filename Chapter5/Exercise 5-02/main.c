/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-02, Chapter5.
 */

#include <stdio.h>
#include <ctype.h>
#include "getch.h"

#define SIZE 10

int getfloat(double *);

int main(void)
{
    int n;
    double array[SIZE], r;

    for (n = 0; n < SIZE && (r = getfloat(&array[n])) != EOF; n++) {
        if (r)
            printf("you input a number: %g\n", array[n]);
        else
            printf("it is not a number.\n");
    }

    return 0;
}

/* getfloat: get next float number from input into *pn */
int getfloat(double *pn)
{
    double power, base, epower;
    int c, sign, c2, emark, exponent;

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
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    epower = 1;
    if (c == 'e' || c == 'E') {
        emark = c;
        c = getch();
        base = c == '-' ? 0.1 : 10.0;
        if (c == '+' || c == '-') {
            if (!isdigit(c2 = getch())) {
                ungetch(c2);
                ungetch(c);
            } else
                c = c2;
        } else if (!isdigit(c)){
            ungetch(c);
            ungetch(emark);
        }
        for (exponent = 0; isdigit(c); c = getch()) {
            exponent = 10 * exponent + (c- '0');
        }
        while (exponent-- > 0)
            epower *= base;
    }
    *pn *= sign / power * epower;
    if (c != EOF)
        ungetch(c);
    return c;
}
