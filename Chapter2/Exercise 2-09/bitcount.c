/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 2-09, Chapter2.
 */

#include <stdio.h>

int bitcount(unsigned x);

int main(void)
{
    printf("%d\n", bitcount(011111));
    return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x - 1))
        b++;
    return b;
}
