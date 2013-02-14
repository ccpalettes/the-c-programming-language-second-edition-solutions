/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-05, Chapter5.
 */

#include <stdio.h>

int _strncmp(char *s, char *t, int n);

int main(void)
{
    char *s, *t;

    s = "testabc";
    t = "testddc";

    printf("%s cmp %s: %d\n", s, t, _strncmp(s, t, 5));

    return 0;
}

int _strncmp(char *s, char *t, int n)
{
    for (; n-- > 0 && *s == *t; ++s, ++t)
        if (*s == '\0' || n == 0)
            return 0;
    return *s - *t;
}
