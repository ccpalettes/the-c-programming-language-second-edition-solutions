/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 1-18, Chapter1.
 */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);

int main(void)
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len == 1 && line[0] == '\n')
            continue;
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