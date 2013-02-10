/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 2-01, Chapter2.
 */

#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("Range of signed char is [%d, %d].\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of unsigned char is [%u, %u].\n", 0, UCHAR_MAX);
    printf("Range of char is [%d, %d].\n", CHAR_MIN, CHAR_MAX);

    printf("Range of signed short int is [%hd, %hd].\n", SHRT_MIN, SHRT_MAX);
    printf("Range of unsigned short int is [%hu, %hu].\n", 0, USHRT_MAX);

    printf("Range of signed int is [%d, %d].\n", INT_MIN, INT_MAX);
    printf("Range of unsigned int is [%u, %u].\n", 0, UINT_MAX);

    printf("Range of signed long int is [%ld, %ld].\n", LONG_MIN, LONG_MAX);
    printf("Range of unsigned long int is [%lu, %lu].\n", 0, ULONG_MAX);

    return 0;
}