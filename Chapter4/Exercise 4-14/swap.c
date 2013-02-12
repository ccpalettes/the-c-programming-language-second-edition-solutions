/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 4-14, Chapter4.
 */

#include <stdio.h>
#include <string.h>

#define swap(t, x, y) {t tmp; tmp = x; x = y; y = tmp;}

int main(void)
{
    int ia = 20, ib = 35;
    printf("before swap: %d, %d\n", ia, ib);
    swap(int, ia, ib)
    printf(" after swap: %d, %d\n", ia, ib);

    double da = 0.3563, db = 348.34;
    printf("before swap: %6g, %6g\n", da, db);
    swap(double, da, db)
    printf(" after swap: %6g, %6g\n", da, db);

    return 0;
}