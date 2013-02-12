/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 4-02, Chapter4.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int getchars(char s[], int max);
double atof(char s[]);

int main(void)
{
    char s[MAXLINE];

    printf("Input a floating-point number, then press enter:\n");
    while (getchars(s, MAXLINE) == 0)
        ;

    printf("The number is: %lf\n", atof(s));

    return 0;
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

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power, base, epower;
    int i, sign, exponent;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    epower = 1;
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        base = s[i] == '-' ? 0.1 : 10.0;
        if (s[i] == '-' || s[i] == '+')
            i++;
        for (exponent = 0; isdigit(s[i]); i++) {
            exponent = 10 * exponent + (s[i] - '0');
        }
        while (exponent-- > 0)
            epower *= base;
    }
    return sign * val / power * epower;
}