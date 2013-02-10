/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 2-07, Chapter2.
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{
    printf("%u\n", invert(5732, 6, 3));
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{   
    // 000001111100000
    unsigned mask = ~(~0U << n) << (p + 1 - n);
     
    // xxxxx^^^^^xxxxx
    return x ^ mask;
}