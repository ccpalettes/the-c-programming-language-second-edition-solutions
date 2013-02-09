/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 1-12, Chapter1.
 */

#include <stdio.h>

int main(void)
{
    int c, linestarted;

    linestarted = 0;
    printf("Input some characters, then press Ctrl+D.\n");
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n') {
            if (!linestarted) {
                putchar('\n');
                linestarted = 1;
            }
        } else {
            putchar(c);
            linestarted = 0;
        }

    return 0;
}