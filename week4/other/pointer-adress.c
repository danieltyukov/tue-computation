#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[7] = {7, 6, 5, 4, 3, 2, 1};
    int *p = &a[0];
    for (int i = 0; i < 7; i++)
        printf("a[%d]=%d\n", i, a[i]);
    for (int i = 0; i < 7; i++)
        printf("p=%p+%d=%p a[%d]=%d\n", p, i, p + i, i, *(p + i));

    // inside pointer
    printf("%d\n", *p);
    // pointer address
    printf("%p\n", &p);
}