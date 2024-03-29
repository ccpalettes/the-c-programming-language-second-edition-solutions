/**
 * Solution for Exercise 4-11, Chapter4.
 */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MATHLIB '1' /* signal that a library function in math.h was found */
#define VARIABLE '2'

int getop(char []);
void push(double);
double pop(void);

double vars[26];
double last;

int main(void)
{
    int type, v;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case MATHLIB:
            if (strcmp(s, "sin") == 0)
                push(sin(pop()));
            else if (strcmp(s, "cos") == 0)
                push(cos(pop()));
            else if (strcmp(s, "pow") == 0) {
                op2 = pop();
                push(pow(pop(), op2));
            } else if (strcmp(s, "last") == 0) {
                printf("the most recently printed value is %g\n", last);
            } else
                printf("error: unknown command %s\n", s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case VARIABLE:
            v = tolower(s[0]);
            last = vars[v - 'a'] = pop();
            push(last);
            break;
        case '\n':
            printf("= %g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
        break;
        }
    }

    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    static int buf = EOF;
    int i, c, c2;

    // if (buf == EOF)
    //     c = getch();
    // else {
    //     c = buf;
    //     buf = EOF;
    // }

    while ((s[0] = c = (buf == EOF ? getch() : buf)) == ' ' || c == '\t')
        buf = EOF;
    buf = EOF;
    s[1] = '\0';

    i = 0;
    if (isalpha(c)) {
        while (isalpha(s[++i] = c = (buf == EOF ? getch() : buf)))
            buf = EOF;
        buf = EOF;
        s[i] = '\0';
        if (c != EOF)
            buf = c;
        return MATHLIB;
    }

    if (!isdigit(c) && c != '.' && c != '-') {
        if (c == '=') {
            c2 = (buf == EOF ? getch() : buf);
            buf = EOF;
            if (isalpha(c2)) {
                s[0] = c2;
                return VARIABLE;
            } else if (c2 != EOF) {
                buf = c2;
            }
        }
        return c; /* not a number */
    }

    if (c == '-') {
        c2 = (buf == EOF ? getch() : buf);
        buf = EOF;
        if (c2 != EOF)
            buf = c2;
        if (!isdigit(c2) && c2 != '.')
            return c;
    }
    if (isdigit(c) || c == '-') /* collect integer part */            
        while (isdigit(s[++i] = c = (buf == EOF ? getch() : buf))) {
            buf = EOF;
        }
        buf = EOF;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = (buf == EOF ? getch() : buf)))
            buf = EOF;
        buf = EOF;
    s[i] = '\0';
    if (c != EOF)
        buf = c;
    return NUMBER;
}

int getch(void) /* get a (possibly pushed-back) character */
{
    return getchar();
}