/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 4-01, Chapter4.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getchars(char s[], int max);
int strindex(char source[], char searchfor[]);

int main(void)
{
    char source[MAXLINE];
    char pattern[MAXLINE];

    printf("Input source, then press enter:\n");
    while (getchars(source, MAXLINE) == 0)
        ;

    printf("Input pattern, then press enter:\n");
    while (getchars(pattern, MAXLINE) == 0)
        ;

    printf("The position is: %d\n", strindex(source, pattern));

    return 0;
}

int getchars(char s[], int max)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < max - 1)
            s[l++] = c;
    s[l] = '\0';

    return l;
}

int strindex(char s[], char t[])
{
    int sl, tl;
    int i, j, k;
    int c;

    sl = strlen(s);
    tl = strlen(t);
    i = sl - tl;
    while (i >= 0) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
        --i;
    }
    return -1;
}