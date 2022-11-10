#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            return gcd(a - b, b);
        }
        else
        {
            return gcd(a, b - a);
        }
    }
    return a;
}

int read_int()
{
    int x;
    scanf(" %d", &x);
    return x;
}

void print_string(char *s)
{
    printf("%s", s);
}

void print_int(int x)
{
    printf("%d", x);
}

int main(void)
{
    int a, b, c;

    a = read_int();
    b = read_int();

    c = gcd(a, b);

    print_string("result = ");
    print_int(c);
    print_string("\n");
}