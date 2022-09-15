#include <stdio.h>
#include <stdlib.h>

int n;

void f(int *q)
{
    free(q);
    q = (int *)malloc(30 * sizeof(int));
}

int main(void)
{
    // Q 1-10
    printf("Which Excercises Would You Like to Test? ");
    scanf("%d", &n);

    if (n == 1)
    {
        int *p1, *p2;
        p1 = (int *)malloc(10 * sizeof(int));
        p2 = (int *)malloc(10 * sizeof(int));
        f(p1);
        free(p1);
        free(p2);
    }
}