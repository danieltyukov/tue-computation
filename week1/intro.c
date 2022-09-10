#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n;
void print_statements();

int main(void)
{
    printf("Which function would you like to run? ");
    scanf("%d", &n);

    if (n == 2)
    {
        print_statements();
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