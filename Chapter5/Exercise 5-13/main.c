/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-13, Chapter5.
 */

#include <stdio.h>
#include <stdlib.h>
#include "lines.h"

#define DEFAULTTAILNUM 10

char *lineptr[MAXLINES]; /* pointers to text lines */

int main(int argc, char **argv)
{
    int nlines; /* number of input lines read */
    int tailnum, p;
    
    tailnum = DEFAULTTAILNUM;
    if (argc > 1 && **++argv == '-') {
        if ((p = atoi(++(*argv))) > 0)
            tailnum = p;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (nlines < tailnum)
            tailnum = nlines;
        writelines(lineptr + nlines - tailnum, tailnum);
        return 0;
    } else {
        printf("error: input too big\n");
        return 1;
    }
}



