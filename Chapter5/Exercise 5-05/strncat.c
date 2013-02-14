/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-05, Chapter5.
 */

#include <stdio.h>

void _strncat(char *s, char *t, int n);

int main(void)
{
    char *s, *t;

    s = "test";
    t = "ring1234";

    _strncat(s, t, 4);
    printf("cat: %s\n", s);

    return 0;
}

void _strncat(char *s, char *t, int n)
{
    while (*s)
        ++s;
    while (n-- > 0 && *t)
        *s++ = *t++;
    *s = '\0';
}
