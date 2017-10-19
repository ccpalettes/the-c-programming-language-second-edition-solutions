/**
 * 
 * Solution for Exercise 4-13, Chapter4.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getchars(char line[], int max);
void reverse(char s[]);
void reverse_r(char s[], int i, int j);

int main(void)
{
    char s[MAXLINE];

    while (getchars(s, MAXLINE)) {
        reverse(s);
        printf("reverse: %s\n", s);
    }

    return 0;
}

void reverse(char s[])
{
    reverse_r(s, 0, strlen(s) - 1);
}

void reverse_r(char s[], int i, int j)
{
  int temp = s[i];

  if (i<j)
    reverse_r(s, i+1, j);
  s[j-i] = temp;
  if (i==0)
    s[j+1] = '\0';
}

int getchars(char s[], int max)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < max - 1)
            s[l++] = c;
    s[l] = '\0';

    return l;
}
