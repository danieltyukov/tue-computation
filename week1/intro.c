#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n;
void print_statements();
void loops();
void operators();

int main(void)
{
    printf("Which function would you like to run? ");
    scanf("%d", &n);

    if (n == 2)
    {
        print_statements();
    }
    else if (n == 3)
    {
        loops();
    }
    else if (n == 4)
    {
        operators();
    }
    else
    {
        printf("Invalid input. Please try again.\n");
    }
}

void print_statements()
{
    // 2
    printf("Hello, there!\n");

    printf("Hello, there!\nHow are you?\n");

    printf("Hello");
    printf("\nHow ");
    printf("are y");
    printf("ou?\n");

    int i1 = 10, i2 = 200;
    printf("i1=%d i2=%d\n", i1, i2);

    int j, j1 = 10, j2 = 200, j3 = 3000, j4 = 40000;
    j = j1;
    printf("%d\n", j);
    j = j2;
    printf("%d\n", j);
    j = j3;
    printf("%d\n", j);
    j = j4;
    printf("%d\n", j);

    int g, g1 = 10, g2 = 200, g3 = 3000, g4 = 40000;
    g = g1;
    printf("%5d\n", g);
    g = g2;
    printf("%5d\n", g);
    g = g3;
    printf("%5d\n", g);
    g = g4;
    printf("%5d\n", g);
}

void loops()
{
    // 3
    int i;
    for (i = 0; i < 9; i++)
    {
        printf("%d\n", i);
    }
    printf("\n");

    int a;
    for (a = 0; a < 9; a++)
    {
        printf("%d\n", 9 - a);
    }
    printf("\n");

    int b;
    for (b = 9; b >= 0; b--)
    {
        printf("%d\n", b);
    }
    printf("\n");

    int c;
    for (c = 9; c > -1; c--)
    {
        printf("%d\n", c);
    }
    printf("\n");

    int d;
    for (d = 0; 9 >= d; d++)
    {
        printf("%d\n", 9 - d);
    }
    printf("\n");

    int e = 0;
    while (e < 9)
    {
        printf("%d\n", e);
        e++;
    }
    printf("\n");

    int f = 0;
    do
    {
        printf("%d\n", f);
        f++;
    } while (f <= 9);
    printf("\n");

    int g = 9;
    do
    {
        printf("%d\n", g);
        g--;
    } while (g >= 0);
    printf("\n");

    int h = 9;
    do
    {
        h--;
        printf("%d\n", h);
    } while (h > 0);
    printf("\n");

    // endless loop
    // for (;;);

    // endless hello world loop
    // for (;;) printf("Hello!\n");

    // endless hello world loop 2
    // while(1) printf("Hello!\n");

    // endless hello world loop 3
    // do { printf("Hello!\n"); } while (1);

    for (int j = 0; j < 6; j++)
    {
        for (int k = 0; k < j; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 6; i++)
    {
        for (int j = 1; j < 6 - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 5; i >= 0; i--)
    {
        for (int j = 1; j < 6 - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 6; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 6; i++)
    {
        for (int j = 1; j < 6 - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i * 2; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 6; i++)
    {
        for (int j = 1; j < 6 - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("O*");
        }
        printf("O\n");
    }
}

void operators()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d %d %d\n", i, i % 3, i % 2);
    }
    printf("\n");

    int j;
    for (j = 0; j < 10; j++)
    {
        printf("%d=3*%d+%d\n", j, j / 3, j % 3);
    }
}