/**
 * Solution for Exercise 3-04, Chapter3.
 */

#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
    char s[MAXLINE];
    
    itoa(INT_MIN, s);
    printf("%d is converted to %s.\n", INT_MIN, s);
    itoa(826, s);
    printf("%d is converted to %s.\n", 826, s);
    itoa(-2093, s);
    printf("%d is converted to %s.\n", -2093, s);

    return 0;
}

void itoa(int n, char s[])
{
    int i, sign, remainder;

    sign = n;
    i = 0;
    do {
        remainder = n % 10;
        s[i++] = ((sign < 0) ? -remainder : remainder) + '0';
    } while (n /= 10);
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