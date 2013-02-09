/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 1-4, Chapter1.
 */

#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;

    lower = -20; /* lower limit of temperatuire scale */
    upper = 150; /* upper limit */
    step = 10; /* step size */

    printf("  C      F\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius * (9.0 / 5.0) + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}