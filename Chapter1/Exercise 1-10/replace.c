/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 1-10, Chapter1.
 */

#include <stdio.h>

int main(void)
{
    int c;

    printf("Input some characters, then press Ctrl+D.\n");
    while ((c = getchar()) != EOF)
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            printf("%c", c);

    return 0;
}