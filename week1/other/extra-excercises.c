#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n;
void print_statements();
void loops();
void operators();
void input();
void if_statements();
void complex_programs();

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
    else if (n == 5)
    {
        input();
    }
    else if (n == 6)
    {
        if_statements();
    }
    else if (n == 7)
    {
        complex_programs();
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
    // 4
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

void input()
{
    // 5
    int i;
    printf("Integer? ");
    scanf("%d", &i);
    printf("You entered: %d\n", i);

    int i1, i2;
    printf("Integer one? ");
    scanf("%d", &i1);
    printf("Integer two? ");
    scanf("%d", &i2);
    printf("You entered %d and %d\n", i1, i2);

    int j1, j2;
    printf("Two Integegers? ");
    scanf("%d %d", &j1, &j2);
    printf("You entered %d and %d\n", j1, j2);
}

void if_statements()
{
    // 6
    int i = 0;
    scanf("%d", i);
    if (i < 0)
    {
        printf("%d is a negative number\n", i);
    }
    else
    {
        if (i == 0)
        {
            printf("%d is zero\n", i);
        }
        else
        {
            printf("%d is a positive number\n", i);
        }
    }

    int a = 0;
    scanf("%d", a);
    if (!(a > 0 || a == 0))
    {
        printf("%d is a negative number\n", a);
    }
    else
    {
        if (!(a < 0 || a == 0))
        {
            printf("%d is a psoitive number\n", a);
        }
        else
        {
            printf("%d is zero\n", a);
        }
    }

    int b;
    for (b = 0; b < 6; b++)
    {
        if (b % 2 == 0)
            printf("%d is even", b);
        else
            printf("%d is odd", b);
        if (b < 3)
        {
            printf("%d and less than 3\n", b);
        }
        else
        {
            if (b > 3)
                printf("%d and greater than 3\n", b);
            else
                printf("%d and equal to 3\n", b);
        }
    }

    int z;
    for (z = 0; z < 6; z++)
    {
        if (z % 2 == 0 && z < 3)
            printf("%d is even and less than 3\n", z);
        if (z % 2 == 0 && z > 3)
            printf("%d is even and greater than 3\n", z);
        if (z % 2 == 1 && z < 3)
            printf("%d is odd and less than 3\n", z);
        if (z % 2 == 1 && z > 3)
            printf("%d is odd and greater than 3\n", z);
        if (z == 3)
            printf("3 is odd and equal to 3\n");
    }

    for (i = 0; i < 6; i++)
    {
        if (i == 3)
            printf("3 is odd and equal to 3\n");
        else if (!(i % 2 != 0 || i > 3))
            printf("%d is even and less than 3\n", i);
        else if (!(i % 2 != 0 || i < 3))
            printf("%d is even and greater than 3\n", i);
        else if (!(i % 2 != 1 || i > 3))
            printf("%d is odd and less than 3\n", i);
        else if (!(i % 2 != 1 || i < 3))
            printf("%d is odd and greater than 3\n", i);
    }
}

void complex_programs()
{
    // 7
    // fabonacci
    int first = 1, second = 1, sum = 2;
    printf("1\n1\n");
    while (sum < 100)
    {
        printf("%d\n", sum);
        first = second;
        second = sum;
        sum = first + second;
    }
    printf("\n");

    // prime numbers
    int i = 11;
    int divisors = 0;
    for (int d = 1; d <= i; d++)
    {
        if (i % d == 0)
            divisors++;
    }
    if (divisors == 2)
        printf("%d is a prime\n", i);
    else
        printf("%d is not a prime\n", i);

    printf("\n");

    // optimized prime numbers
    int j = 11;
    int divisors2 = 2;
    for (int d = 2; d < j && divisors2 == 2; d++)
    {
        if (j % d == 0)
            divisors2++;
    }
    if (divisors2 == 2)
        printf("%d is a prime\n", j);
    else
        printf("%d is not a prime\n", j);

    printf("\n");

    // normal to roman numbers
    int stop = 0;
    do
    {
        int i;
        printf("Number? ");
        scanf("%d", &i);
        if (i == 0)
            stop = 1;
        while (i >= 1000)
        {
            printf("M");
            i -= 1000;
        }
        while (i >= 500)
        {
            printf("D");
            i -= 500;
        }
        while (i >= 100)
        {
            printf("C");
            i -= 100;
        }
        while (i >= 50)
        {
            printf("L");
            i -= 50;
        }
        while (i >= 10)
        {
            printf("X");
            i -= 10;
        }
        while (i >= 5)
        {
            printf("V");
            i -= 5;
        }
        while (i >= 1)
        {
            printf("I");
            i -= 1;
        }
        if (!stop)
            printf("\n");
    } while (!stop);
    printf("Bye!\n");
    printf("\n");

    // valid values checker
    int k, valid_values;
    printf("Integer? ");
    valid_values = scanf("%d", &k);
    if (valid_values == 1)
        printf("You entered: %d\n", k);
    else
        printf("You did not enter an integer!\n");
}