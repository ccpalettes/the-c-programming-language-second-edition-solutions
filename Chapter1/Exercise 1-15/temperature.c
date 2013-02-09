/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 1-15, Chapter1.
 */

#include <stdio.h>

float ftoc(float fahr);

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0; /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahr = lower;

    while (fahr <= upper) {
        celsius = ftoc(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

float ftoc(float fahr)
{
    float celsius;
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    return celsius;
}