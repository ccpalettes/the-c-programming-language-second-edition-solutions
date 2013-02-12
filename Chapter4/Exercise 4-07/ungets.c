/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 4-07, Chapter4.
 */

#include <stdio.h>
#include <string.h>

int getch(void);
void ungetch(int);
void ungets(char s[]);

int main(void)
{
    ungets("testring");
    putchar(getch());
    putchar(getch());
    putchar(getch());
    putchar(getch());
    putchar(getch());
    putchar(getch());
    putchar(getch());
    putchar(getch());

    return 0;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[])
{    
  int l = strlen(s);

  while (l)
    ungetch(s[--l]);
}