/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-04, Chapter5.
 */

#include <stdio.h>

#define MAXLINE 1000

int strend(char *s, char *t);
int getchars(char *s, int max);

int main(void)
{
    char *s, *t;

    printf("input string s: \n");
    while (getchars(s, MAXLINE) == 0)
        ;
    printf("input string t: \n");
    while (getchars(t, MAXLINE) == 0)
        ;

    printf("string t is%s at the end of the string s.\n", strend(s, t) ? "" : " not");

    return 0;
}

int strend(char *s, char *t)
{
    int sl, tl;

    sl = tl = 0;
    while (*s++)
        sl++;
    while (*t++)
        tl++;

    if (sl >= tl) {
        s -= tl;
        t -= tl;
        while (*s++ == *t++)
            if (!*s)
                return 1;
    }

    return 0;

}

int getchars(char *s, int max)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < max - 1) {
            *s++ = c;
            ++l;
        }
    *s = '\0';

    return l;
}