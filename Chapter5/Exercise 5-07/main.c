/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-07, Chapter5.
 */

#include <stdio.h>
#include "lines.h"
#include "qsort.h"

char *lineptr[MAXLINES]; /* pointers to text lines */

/* sort input lines */
int main(void)
{
    int nlines; /* number of input lines read */
    int i;

    char s[MAXLINES][MAXLEN];

    for (i = 0; i < MAXLINES; ++i) {
        *(lineptr + i) = s[i];
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}