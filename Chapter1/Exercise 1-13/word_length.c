/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 1-13, Chapter1.
 */

#include <stdio.h>

#define MAX_LENGTH 15
#define IN_WORD 1
#define OUT_WORD 0

int main(void)
{
    int c, word_in_out;
    int word_length[MAX_LENGTH + 1];
    int l;
    int i, j;
    unsigned int max_count;

    for (i = 0; i <= MAX_LENGTH; ++i)
        word_length[i] = 0;

    word_in_out = OUT_WORD;
    printf("Input some characters, then press Ctrl+D.\n");
    while (1) {
        c = getchar();
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (word_in_out == OUT_WORD) {
                l = 0;
                word_in_out = IN_WORD;
            }
            ++l;
        } else {
            if (word_in_out == IN_WORD) {
                if (l <= MAX_LENGTH)
                    ++word_length[l - 1];
                else
                    ++word_length[MAX_LENGTH];
                word_in_out = OUT_WORD;
            }
            if (c == EOF)
                break;
        }
    }

    printf("\nHorizontal histogram:\n\n");
    printf(" length | graph\n");
    for (i = 0; i <= MAX_LENGTH; ++i) {
        if (i != MAX_LENGTH)
            printf("     %2d | ", i + 1);
        else
            printf("    >%2d | ", MAX_LENGTH);
        for (j = 0; j < word_length[i]; ++j)
            putchar('+');
        putchar('\n');
    }

    printf("\nVertical histogram:\n\n");
    max_count = 0;
    for (i = 0; i <= MAX_LENGTH; ++i)
        if (word_length[i] > max_count)
            max_count = word_length[i];

    for (i = 0; i < max_count; ++i) {
        printf("  %2u | ", max_count - i);
        for (j = 0; j <= MAX_LENGTH; ++j)
            if (word_length[j] >= max_count - i)
                printf("  +");
            else
                printf("   ");
        printf("\n");
    }

    printf(" ------");
    for (i = 0; i <= MAX_LENGTH; ++i)
        printf("---");
    printf("--\n");

    printf("       ");
    for (i = 0; i < MAX_LENGTH;)
        printf(" %2u", ++i);
    printf(" >%2u", MAX_LENGTH);
    printf("\n");

    return 0;
}