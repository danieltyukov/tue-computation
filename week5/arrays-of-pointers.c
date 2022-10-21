#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 4

int main(void)
{
    int *a[ROWS];
    for (int r = 0; r < ROWS; r++)
    {
        a[r] = (int *)malloc((r + 1) * sizeof(int));
        for (int c = 0; c <= r; c++)
        {
            a[r][c] = 10 * r + c;
        }
    }
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c <= r; c++)
        {
            printf("a[%d][%d]=%d address %p\n", r, c, a[r][c], &a[r][c]);
        }
    }
}
