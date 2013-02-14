/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-12, Chapter5.
 */

#include <stdio.h>
#include <stdlib.h> /* for atoi() */

#define MAXLINE 1000
#define DEFAULTSTARTCOL 1
#define DEFAULTTABWIDTH 8

int getchars(char *s, int max);
void detab(char *s1, char *s2, int startcol, int tabwidth);

int main(int argc, char **argv)
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    int m, n, m2, n2;

    m = DEFAULTSTARTCOL;
    n = DEFAULTTABWIDTH;

    while (--argc > 0) {
        argv++;
        if (**argv == '-') {
            if ((m2 = atoi(++*argv)) > 0)
                m = m2;
        } else if (**argv == '+') {
            if ((n2 = atoi(++*argv)) > 0)
                n = n2;
        }
    }

    printf("Usage example: detab -2 +8\n");

    printf("Input some characters, then press enter:\n");
    while (getchars(s1, MAXLINE) == 0)
        ;

    detab(s1, s2, m, n);
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

void detab(char *s1, char *s2, int col, int w)
{
    int j, l, c, blanks;

    l = 0;
    while ((c = *s1++) != '\0') {
        if (c == '\t') {
            blanks = w - l % w;
            if (l >= col - 1) {
                for (j = 0; j < blanks; ++j) {
                    *s2++ = ' ';
                    l++;
                }
            } else {
                *s2++ = c;
                l += blanks;
            }
        } else {
            *s2++ = c;
            l++;
        }
    }
    *s2 = '\0';
}