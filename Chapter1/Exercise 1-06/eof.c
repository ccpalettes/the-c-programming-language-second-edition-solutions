/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 1-6, Chapter1.
 */

#include <stdio.h>

int main(void)
{
    printf("Please enter a character:\n");
    printf("The expression \"getchar() != EOF\" is %d.\n", getchar() != EOF);
    return 0;
}