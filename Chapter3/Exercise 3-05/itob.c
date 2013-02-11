/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 3-05, Chapter3.
 */

#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    char s[MAXLINE];
    
    itob(INT_MIN, s, 16);
    printf("%d in base %d is %s.\n", INT_MIN, 16, s);
    itob(826, s, 10);
    printf("%d in base %d is %s.\n", 826, 10, s);
    itob(-2093, s, 5);
    printf("%d in base %d is %s.\n", -2093, 5, s);

    return 0;
}

void itob(int n, char s[], int b)
{
    int i, sign, remainder;
    char bases[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (b < 2 || b > 36)
        return;

    sign = n;
    i = 0;
    do {
        remainder = n % b;
        s[i++] = ((sign < 0) ? -remainder : remainder) + '0';
    } while (n /= b);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, j;
    int tmp;

    for (j = 0; s[j] != '\0'; ++j)
        ;
    --j;

    for (i = 0; i < j; ++i, --j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}