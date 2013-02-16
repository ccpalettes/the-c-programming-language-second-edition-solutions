/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 1-23, Chapter1.
 */

/**
 * Test text, replace '@' with '/'

 @**
  * Hello World
  *@
 #include <stdio.h> // for printf

 int main(void)
 {
     char s[] = "// hello \
         world!\n";
     printf("%s\n", s);
 
     return 0;
 }

 */


#include <stdio.h>

#define MAXLENGTH 5000

int _getline(char s[], int max);

int main(void)
{
    int len, i;
    char s[MAXLENGTH];

    
    printf("Input code, then press Ctrl+D:\n");
    while ((len = _getline(s, MAXLENGTH)) > 0) {
        printf("\nResult:\n=========================\n");
        i = 0;
        while (s[i] != '\0') {
            if (s[i] == '/' && s[i+1] == '/') {
                i += 2;
                while (s[i] != '\n' && s[i] != '\0')
                    ++i;
            } else if (s[i] == '/' && s[i+1] == '*') {
                i += 2;
                while (s[i] != '\0' && s[i+1] != '\0' && (s[i] != '*' || s[i+1] != '/'))
                    ++i;
                if (s[i] != '\0' && s[i+1] == '\0')
                    ++i;
                if (s[i] == '*')
                    i += 2;
            } else if (s[i] == '\"') {
                putchar('\"');
                ++i;
                while (s[i] != '\0' && (s[i-1] == '\\' || s[i] != '\"'))
                    putchar(s[i++]);
            } else {
                putchar(s[i++]);
            }
        }
    }
    
    return 0;
}

int _getline(char s[], int max)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF; ++i)
        if (i < max - 1)
            s[l++] = c;
    s[l] = '\0';

    return l;
}