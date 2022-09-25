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

    int d[N]; // unitialised, contains random values
    int min, max, sum;
    for (int i = 0; i < N; i++)
    {
        printf("value %d? ", i);
        scanf("%d", &d[i]);
    }
    min = d[0];
    max = d[0];
    sum = 0;
    for (int i = 0; i < N; i++)
    {
        printf("%d,", d[i]);
        if (d[i] < min)
            min = d[i];
        if (d[i] > max)
            max = d[i];
        sum = sum + d[i];
    }
    printf("\n");
    printf("min=%d\n", min);
    printf("max=%d\n", max);
    printf("sum=%d\n", sum);

    int e[N];
    int reverse[N];
    for (int i = 0; i < N; i++)
    {
        printf("value %d? ", i);
        scanf("%d", &e[i]);
    }
    for (int i = 0; i < N; i++)
    {
        reverse[N - 1 - i] = e[i];
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d,", reverse[i]);
    }
    printf("\n");

// Ask for the length of an array until it is between 1 and 100. Read all entries in the array from the
// terminal. Print all even numbers in the array in reverse order, but without using a second array.
#define B 100
    int f[B];
    int length = 0;
    do
    {
        printf("length? ");
        scanf("%d", &length);
    } while (length < 1 || length > 100);
    for (int i = 0; i < length; i++)
    {
        printf("value %d? ", i);
        scanf("%d", &f[i]);
    }
    for (int i = length - 1; i >= 0; i--)
    {
        if (f[i] % 2 == 0)
            printf("%d\n", f[i]);
    }
}

void character_arrays()
{
#define A 6
    char a[A];
    printf("characters? ");
    for (int i = 0; i < A; i++)
    {
        scanf("%c", &a[i]);
    }
    for (int i = 0; i < A; i++)
    {
        printf("’%c’,", a[i]);
    }
    printf("\n");

    char b[A];
    printf("characters? ");
    for (int i = 0; i < A; i++)
    {
        scanf("%c", &b[i]);
    }
    int digits = 0;
    for (int i = 0; i < A; i++)
    {
        if (b[i] >= '0' && b[i] <= '9')
        {
            printf("’%c’,", b[i]);
            digits++;
        }
    }
    if (digits > 0)
        printf("\n");

    char c[A];
    int number = 0;
    printf("characters? ");
    for (int i = 0; i < A; i++)
    {
        scanf("%c", &c[i]);
    }
    int debug = 0;
    for (int i = 0; i < A; i++)
    {
        if (c[i] >= '0' && c[i] <= '9')
        {
            number = number * 10;
            if (debug)
                printf("convert character ’%c’ to integer %d\n", c[i], c[i] - '0');
            if (debug)
                printf("number = number(%d) + digit(%d)\n", number, c[i] - '0');
            number += (c[i] - '0');
        }
    }
    printf("%d\n", number);

    // Write a program that reads N=6 characters into an array. Compute and print the binary number corre-
    // sponding to the characters that are binary digits.
    char d[N];
    int number1 = 0;
    printf("characters? ");
    for (int i = 0; i < N; i++)
    {
        scanf("%c", &d[i]);
    }
    for (int i = 0; i < N; i++)
    {
        if (d[i] >= '0' && d[i] <= '1')
            number1 = number1 * 2 + (a[i] - '1');
    }
    printf("%d\n", number1);
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
        character_arrays();
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
