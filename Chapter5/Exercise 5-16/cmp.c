/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-16, Chapter5.
 */

#include <stdlib.h>

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int strcmpignore(char *s1, char *s2)
{
    for (; tolower(*s1) == tolower(*s2); ++s1, ++s2)
        if (*s1 == '\0')
            return 0;
    return tolower(*s1) - tolower(*s2);
}