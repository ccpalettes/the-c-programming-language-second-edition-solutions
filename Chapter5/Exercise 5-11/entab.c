/**
 * Solution for Exercise 5-11, Chapter5.
 */

#include <stdio.h>
#include <stdlib.h> /* for atoi() */

#define MAXLINE 1000
#define DEFAULTTABWIDTH 8
#define MAXTABSTOPS 10

int getchars(char *s, int max);
void entab(char *s1, char *s2, int tabwidth[]);

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

    printf("Usage example: entab 2 4 6\n");

    printf("Input some characters, then press enter:\n");
    while (getchars(s1, MAXLINE) == 0)
        ;

    entab(s1, s2, w);
    printf("entab result:\n%s\n", s2);

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

// copy characters in s1 to s2 and replace blanks with tabs
void entab(char *s1, char *s2, int w[])
{
    int i, j, c, blanks, k;
    int blanksenough;

    i = 0;
    k = 0;
    while ((c = *s1) != '\0') {
        if (c == ' ') {
            blanksenough = 1;
            if (w[k] == 0)
                k = 0;
            blanks = w[k] - i % w[k];
            k++;
            for (j = 1; j < blanks; ++j){
                if (*(s1 + j) != ' ') {
                    blanksenough = 0;
                    break;
                }
            }
            if (blanksenough) {
                *s2++ = '\t';
                s1 += blanks;
                i += blanks;
            } else {
                *s2++ = c;
                i++;
                ++s1;
            }
        } else {
            *s2++ = c;
            i++;
            ++s1;
        }
    }
    *s2++ = '\0';
}