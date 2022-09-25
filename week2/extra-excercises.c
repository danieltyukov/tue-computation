#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void basic_data_types()
{
    int a = 1;
    float b = 2;  // automatically converted to 2.0
    double c = 3; // automatically converted to 3.0
    printf("integer %d\n", a);
    printf("float %f\n", b);
    printf("double %e\n", c);

    int d;
    float e;
    printf("integer? ");
    scanf("%d", &d);
    printf("float? ");
    scanf("%f", &e);
    printf("integer %+06d\n", d);
    printf("float %06.2d\n", e);
    printf("float %+06.2e\n", e);

    // with such method its possible to skip new lines and spaces
    char f;
    printf("character? ");
    scanf(" %c", &f);
    printf("character ’%c’\n", f);

    char g;
    printf("character? ");
    scanf("%c", &g);
    // or c = getchar();
    printf("character ’%c’\n", g);
}

void integer_arrays()
{
#define N 6

    int a[N] = {0, 0, 0, 0, 0, 0};
    // int a[] = { 0, 0, 0, 0, 0, 0 }; // the length 6 is computed automatically
    // int a[N] = { 0 }; // the remaining values are initialised to 0 automatically
    for (int i = 0; i < N; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");

    int b[N]; // unitialised, contains random values
    for (int i = 0; i < N; i++)
    {
        printf("value %d? ", i);
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d,", b[i]);
    }
    printf("\n");

    int c[N]; // unitialised, contains random values
    for (int i = 0; i < N; i++)
    {
        printf("value %d? ", i);
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < N; i++)
    {
        if (i != N - 1)
            printf("%d,", c[i]);
        else
            printf("%d\n", c[i]);
    }
    // alternatively:
    for (int i = 0; i < N - 1; i++)
        printf("%d,", c[i]);
    printf("%d\n", c[N - 1]);
    // be careful not to accidentally use a[N], which is undefined (and wrong)
}

int main(void)
{
    int n;
    printf("Which function would you like to run? ");
    scanf("%d", &n);

    if (n == 2)
    {
        basic_data_types();
    }
    else if (n == 3)
    {
        integer_arrays();
    }
    else if (n == 4)
    {
    }
    else if (n == 5)
    {
    }
    else if (n == 6)
    {
    }
    else if (n == 7)
    {
    }
    else
    {
        printf("Invalid input. Please try again.\n");
    }
}
