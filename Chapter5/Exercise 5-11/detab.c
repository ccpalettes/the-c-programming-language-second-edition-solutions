/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-11, Chapter5.
 */

#include <stdio.h>
#include <stdlib.h> /* for atoi() */

#define MAXLINE 1000
#define DEFAULTTABWIDTH 4
#define MAXTABSTOPS 10

int getchars(char *s, int max);
void detab(char *s1, char *s2, int tabwidth[]);

int main(int argc, char **argv)
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    int w[MAXTABSTOPS + 1];
    int i, tab, j;

    if (argc > MAXTABSTOPS)
        argc = MAXTABSTOPS;
    j = 0;
    for (i = 2; i <= argc; ++i) {
        tab = atoi(*++argv);
        if (tab > 0)
            w[j++] = tab;
    }
    if (i == 2)
        w[j++] = DEFAULTTABWIDTH;
    w[j] = 0;

    printf("Usage example: detab 2 4 6\n");

    printf("Input some characters, then press enter:\n");
    while (getchars(s1, MAXLINE) == 0)
        ;

    detab(s1, s2, w);
    printf("detab result:\n%s\n", s2);

    return 0;
}

int getchars(char *s, int max)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < max - 1) {
            *s++ = c;
            l++;
        }
    *s = '\0';

    return l;
}

// copy characters in s1 to s2 and replace tabs with proper number of blanks
void detab(char *s1, char *s2, int w[])
{
    int j, l, c, blanks, k;

    l = 0;
    k = 0;
    while ((c = *s1++) != '\0') {
        if (c == '\t') {
            if (w[k] == 0)
                k = 0;
            blanks = w[k] - l % w[k];
            k++;
            for (j = 0; j < blanks; ++j) {
                *s2++ = ' ';
                l++;
            }
        } else {
            *s2++ = c;
            l++;
        }
    }
    *s2 = '\0';
}