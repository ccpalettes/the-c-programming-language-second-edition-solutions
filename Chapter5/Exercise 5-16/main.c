/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-16, Chapter5.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lines.h"
#include "qsort.h"
#include "cmp.h"

int strcompare(char *s1, char *s2);
int isdirectory(char *s);

char *lineptr[MAXLINES]; /* pointers to text lines */

int ignorecase = 0; /* 1 if case insensitive */
int directory = 0; /* 1 if sorting in directory order */

int main(int argc, char **argv)
{
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    int order = 1; /* 1 if sorting in increasing order*/

    int c, i;
    char *t;

    while (--argc > 0 && *(*++argv) == '-') {
        while ((c = *++(*argv)) != '\0') {
            switch (c) {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    order = 0;
                    break;
                case 'f':
                    ignorecase = 1;
                    break;
                case 'd':
                    directory = 1;
                    break;
                default:
                    break;
            }
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void**) lineptr, 0, nlines-1,
            (int (*)(void*,void*))(numeric ? numcmp : strcompare), order);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int strcompare(char *s1, char *s2)
{
    if (directory) {
        while(*s1 != '\0' && !isdirectory(s1))
            s1++;
        while(*s2 != '\0' && !isdirectory(s2))
            s2++;
        if (ignorecase) {
            while (tolower(*s1) == tolower(*s2)) {
                if (*s1 == '\0')
                    return 0;
                s1++;
                s2++;
                while(*s1 != '\0' && !isdirectory(s1))
                    s1++;
                while(*s2 != '\0' && !isdirectory(s2))
                    s2++;
            }
            return tolower(*s1) - tolower(*s2);
        } else {
            printf("dsdsd\n");
            while (*s1 == *s2) {
                if (*s1 == '\0')
                    return 0;
                s1++;
                s2++;
                while(*s1 != '\0' && !isdirectory(s1))
                    s1++;
                while(*s2 != '\0' && !isdirectory(s2))
                    s2++;
            }
            return *s1 - *s2;
        }
    } else {
        if (ignorecase) {
            return strcmpignore(s1, s2);
        } else {
            return strcmp(s1, s2);
        }
    }
}

int isdirectory(char *s)
{
    return isdigit(*s) || isalpha(*s) || isspace(*s);
}
