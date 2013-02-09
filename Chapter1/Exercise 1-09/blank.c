/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 1-9, Chapter1.
 */

#include <stdio.h>

int main(void)
{
    int c, blank_recieved;
    blank_recieved = 0;
    printf("Input some characters, when you finishes, press Ctrl+D.\n");
    while ((c = getchar()) != EOF)
        if (c == ' ') {
            if (!blank_recieved) {
                blank_recieved = 1;
                putchar(c);
            }
        } else {
            blank_recieved = 0;
            putchar(c);
        }

    return 0;
}