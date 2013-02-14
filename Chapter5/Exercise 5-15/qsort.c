/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-15, Chapter5.
 */

#include <string.h>

/* qsort: sort v[left]...v[right] into increasing/decreasing order */
void qsort(void *v[], int left, int right, int (*comp)(void *, void *), int order)
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (order && (*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
        else if (!order && (*comp)(v[i], v[left]) > 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1, comp, order);
    qsort(v, last+1, right, comp, order);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
