/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-03, Chapter5.
 */

#include <stdio.h>

#define MAXLINE 1000

void str_cat(char *s, char *t);
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

    str_cat(s, t);
    printf("cat: %s\n", s);

    return 0;
}

void str_cat(char *s, char *t)
{
    while (*s)
        ++s;
    while (*s++ = *t++)
        ;
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