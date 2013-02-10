/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 2-10, Chapter2.
 */

#include <stdio.h>

int lower(int c);

int main(void)
{
    char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;

    i = 0;
    while (s[i] != '\0') {
        printf("%c -> %c\n", s[i], lower(s[i]));
        i++;
    }

    return 0;
}

int lower(int c)
{
    return (c >= 'A' && c<= 'Z') ? c + 'a' - 'A' : c;
}
