#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Arrays of Pointers
void func1()
{
    int i = 11, j = 22, k = 33;
    int a[3];
    int *pa[3];
    a[0] = i;
    a[1] = j;
    a[2] = k;
    pa[0] = &i;
    pa[1] = &j;
    pa[2] = &k;
    for (int x = 0; x < 3; x++)
        printf("a[%d]=%d\n", x, a[x]);
    for (int x = 0; x < 3; x++)
        printf("pa[%d]=%p\n", x, pa[x]);
    for (int x = 0; x < 3; x++)
        printf("*pa[%d]=%d\n", x, *pa[x]);
}

void func2()
{
    double a[4];
    double *pa[4];
    for (int x = 0; x < 4; x++)
        a[x] = 100 * x;
    for (int x = 0; x < 4; x++)
        pa[x] = &a[x];
    for (int x = 0; x < 4; x++)
        printf("a[%d]=%f\n", x, a[x]);
    for (int x = 0; x < 4; x++)
        printf("pa[%d]=%p\n", x, pa[x]);
    for (int x = 0; x < 4; x++)
        printf("*pa[%d]=%f\n", x, *pa[x]);
}

void func3()
{
    char a[] = "another one bites the dust";
    char *pa[5] = {&a[0], &a[8], &a[12], &a[18], &a[22]};
    // or: char *pa[5] = { a+0, a+8, a+12, a+18, a+22 };
    printf("a=\"%s\"\n", a);
    for (int x = 0; x < 5; x++)
        printf("pa[%d]=%p\n", x, pa[x]);
    for (int x = 0; x < 5; x++)
        printf("pa[%d]=\"%s\"\n", x, pa[x]);
    for (int x = 0; x < 5; x++)
        printf("*pa[%d]=’%c’\n", x, *pa[x]);
}

int main(void)
{
}