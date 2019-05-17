/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 2-04, Chapter2.
 */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void squeeze(char s1[], char s2[]);

int main(void)
{
    int len;
    char s1[MAXLINE];
    char s2[MAXLINE];

    printf("Input string s1:\n");
    while ((len = get_line(s1, MAXLINE)) == 0)
        ;

    printf("Input string s2:\n");
    while ((len = get_line(s2, MAXLINE)) == 0)
        ;

    squeeze(s1, s2);
    printf("Result is %s\n", s1);

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 1)
            s[l++] = c;
    s[l] = '\0';

    return l;
}

/* This implementation is a bit more complicated*/
void squeeze(char s1[], char s2[])
{
    int i, j, k;

    i = 0;
    while (s2[i] != '\0') {
        j = 0;
        while (s1[j] != '\0') {
            if (s1[j] == s2[i]) {
                k = j;
                while ((s1[k] = s1[k + 1]) != '\0'){
                    ++k;
                }
            } else
                ++j;
        }
        ++i;
    }
}
