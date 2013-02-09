/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 1-14, Chapter1.
 */

#include <stdio.h>

#define NUM_CHARS 128
#define IN_WORD 1
#define OUT_WORD 0

int main(void)
{
    int c;
    int char_frequencies[NUM_CHARS + 1];
    int i;

    for (i = 0; i <= NUM_CHARS; ++i)
        char_frequencies[i] = 0;

    printf("Input some characters, then press Ctrl+D.\n");
    while ((c = getchar()) != EOF)
        ++char_frequencies[c];

    printf("\n ASCII | Count\n");
    for (i = 0; i <= NUM_CHARS; ++i) 
        if (char_frequencies[i] > 0)
            printf(" %5d : %5d\n", i, char_frequencies[i]);

    return 0;
}