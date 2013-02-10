/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 2-06, Chapter2.
 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    printf("%u\n", setbits(5732, 6, 3, 9823));
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    // xxxxx00000xxxxx
    unsigned a = x & ~(~(~0U << n) << (p + 1 - n));

    // 00000yyyyy00000
    unsigned b = (y & ~(~0U << n)) << (p + 1 - n);

    // xxxxxyyyyyxxxxx
    return a | b;
}