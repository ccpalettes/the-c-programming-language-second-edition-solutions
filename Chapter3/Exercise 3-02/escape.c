/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 3-02, Chapter3.
 */

#include <stdio.h>

#define MAXLINE 1000

int getchars(char line[], int maxline);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void)
{
    char t[MAXLINE];
    char s1[MAXLINE];
    char s2[MAXLINE];

    printf("Input some characters, then press Ctrl+D:\n");
    while (getchars(t, MAXLINE) == 0)
        ;

    escape(s1, t);
    printf("\nescape result:\n%s\n", s1);
    
    unescape(s2, s1);
    printf("unescape result:\n%s\n", s2);

    return 0;
}

int getchars(char s[], int lim)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF; ++i)
        if (i < lim - 1)
            s[l++] = c;
    s[l] = '\0';

    return l;
}

void escape(char s[], char t[])
{
    int i, j;

    for (i = 0, j = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
        case '\n':
            s[j++] =  '\\';
            s[j++] =  'n';
            break;
        case '\t':
            s[j++] =  '\\';
            s[j++] =  't';
            break;
        case '\v':
            s[j++] =  '\\';
            s[j++] =  'v';
            break;
        case '\b':
            s[j++] =  '\\';
            s[j++] =  'b';
            break;
        case '\r':
            s[j++] =  '\\';
            s[j++] =  'r';
            break;
        case '\f':
            s[j++] =  '\\';
            s[j++] =  'f';
            break;
        case '\a':
            s[j++] =  '\\';
            s[j++] =  'a';
            break;
        case '\\':
            s[j++] =  '\\';
            s[j++] =  '\\';
            break;
        case '\?':
            s[j++] =  '\\';
            s[j++] =  '\?';
            break;
        case '\'':
            s[j++] =  '\\';
            s[j++] =  '\'';
            break;
        case '\"':
            s[j++] =  '\\';
            s[j++] =  '\"';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j;

    for (i = 0, j = 0; t[i] != '\0'; ++i) {
        if (t[i] == '\\') {
            switch (t[++i]) {
            case 'n':
                s[j++] =  '\n';
                break;
            case 't':
                s[j++] =  '\t';
                break;
            case 'v':
                s[j++] =  '\v';
                break;
            case 'b':
                s[j++] =  '\b';
                break;
            case 'r':
                s[j++] =  '\r';
                break;
            case 'f':
                s[j++] =  '\f';
                break;
            case 'a':
                s[j++] =  '\a';
                break;
            case '\\':
                s[j++] =  '\\';
                break;
            case '\?':
                s[j++] =  '\?';
                break;
            case '\'':
                s[j++] =  '\'';
                break;
            case '\"':
                s[j++] =  '\"';
                break;
            // actually, cases below should never happen if the input string is correct.
            case '\0':
            default:
                s[j++] = '\\';
                --i;
                break;
            }
        } else {
            s[j++] =  t[i];
        }
    }
    s[j] = '\0';
}