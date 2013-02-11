/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 1-20, Chapter1.
 */

#include <stdio.h>

#define MAXLINE 1000
#define TAB_WIDTH 4

int getchars(char s[], int maxline);
void detab(char s1[], char s2[], int tabwidth);

int main(void)
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    printf("Input some characters, then press enter:\n");
    while (getchars(s1, MAXLINE) == 0)
        ;

    detab(s1, s2, TAB_WIDTH);
    printf("detab result:\n%s\n", s2);

    return 0;
}

int getchars(char s[], int lim)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 1)
          s[l++] = c;
    s[l] = '\0';

    return l;
}

// copy characters in s1 to s2 and replace tabs with proper number of blanks
void detab(char s1[], char s2[], int w)
{
    int i, j, l, c, blanks;

    i = 0;
    l = 0;
    while ((c = s1[i++]) != '\0') {
        if (c == '\t') {
            blanks = w - l % w;
            for (j = 0; j < blanks; ++j)
                s2[l++] = ' ';
        } else {
            s2[l++] = c;
        }
    }
    s2[l] = '\0';
}