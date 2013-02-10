/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 2-02, Chapter2.
 */

#include <stdio.h>

#define MAXLINE 1000

int main(void)
{
    char line[MAXLINE];
    int c, i;

    i = 0;
    while (i < MAXLINE - 1) {
    if ((c=getchar()) == EOF)
        break;
    line[i++] = c;
    if (c == '\n')
        break;
    }
    line[i] = '\0';

    printf("%s\n", line);

    return 0;
}