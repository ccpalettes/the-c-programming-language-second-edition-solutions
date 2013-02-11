/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 1-19, Chapter1.
 */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char s[]);

int main(void)
{
    char line[MAXLINE]; /* current input line */

    while (get_line(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 1)
            s[l++] = c;
    if (c == '\n' && l < lim - 1)
        s[l++] = c;
    s[l] = '\0';

    return l;
}

void reverse(char s[])
{
    int i, j;
    int tmp;

    for (j = 0; s[j] != '\0'; ++j)
        ;
    --j;
    if (s[j - 1] == '\n')
        --j;

    for (i = 0; i < j; ++i, --j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}