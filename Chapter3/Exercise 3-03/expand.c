/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 3-03, Chapter3.
 */

#include <stdio.h>

#define MAXLINE 1000

int getchars(char line[], int maxline);
void expand(char s1[], char s2[]);

int main(void)
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    printf("Input some characters, then press enter:\n");
    while (getchars(s1, MAXLINE) == 0)
        ;

    expand(s1, s2);
    printf("\nThe expanded result is:\n%s\n", s2);

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

void expand(char s1[], char s2[])
{
    int i, j, k;
    int c;

    for (i = 0, j = 0; s1[i] != '\0'; ++i) {
        if (s1[i+1] == '-' && (c = s1[i+2]) != '\0' &&
            (('a' <= s1[i] && s1[i] <= 'z' && s1[i] <= c && c <= 'z') ||
            ('A' <= s1[i] && s1[i] <= 'Z' && s1[i] <= c && c <= 'Z') ||
            ('0' <= s1[i] && s1[i] <= '9' && s1[i] <= c && c <= '9'))) {
                k = 0;
                while (k <= c - s1[i])
                    s2[j++] = s1[i] + k++;
                i += 2;
        } else {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}