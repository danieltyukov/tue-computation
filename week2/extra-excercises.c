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

int plus2(int a, int b)
{
    return a + b;
}
int plus3(int a, int b, int c)
{
    int ab = plus2(a, b);
    int abc = plus2(ab, c);
    return abc;
}
int plus6(int a[N])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += a[i];
    return sum;
}
int plusn(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}
int vectormult(int a[N], int b[N])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += (a[i] * b[i]);
    return sum;
}
int vectormult2(int a[N], int b[N])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum = plus2(sum, (a[i] * b[i]));
    return sum;
}
float powr(float b, int e)
{
    float r = 1;
    for (int i = 0; i < e; i++)
        r *= b;
    return r;
}
// recursive function version - calls itself
float powr2(float b, int e)
{
    if (e < 1)
        return 1.0;
    float powr_e_minus_one = powr2(b, e - 1);
    return b * powr_e_minus_one;
}
int sumn(int n)
{
    if (n < 1)
        return 0;
    int sum_of_0_to_n_minus_one = sumn(n - 1);
    return sum_of_0_to_n_minus_one + n;
}
int mystrlen(char s[])
{
    int len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}
void mystrcpy(char s[], char t[])
{
    int len = 0;
    while (s[len] != '\0')
    {
        t[len] = s[len];
        len++;
    }
}
void functions()
{
    printf("1\n");
    int x, y;
    printf("integers? ");
    scanf("%d %d", &x, &y);
    printf("the sum is %d\n", plus2(x, y));

#define Z 6
    printf("3\n");
    int a[Z], sum = 0;
    printf("integers? ");
    for (int i = 0; i < Z; i++)
    {
        scanf("%d", &a[i]);
        sum = plus2(sum, a[i]);
    }
    printf("the sum is %d\n", sum);

    printf("4\n");
    int b[Z];
    printf("integers? ");
    for (int i = 0; i < Z; i++)
    {
        scanf("%d", &b[i]);
    }
    printf("the sum is %d\n", plus3(0, plus3(b[0], b[1], b[2]), plus3(b[3], b[4], b[5])));
    // of course, it would have been smarter to do:
    // printf("the sum is %d\n", plus2(plus3(a[0], a[1], a[2]), plus3(a[3], a[4], a[5])));

    printf("5\n");
    int c[Z];
    printf("integers? ");
    for (int i = 0; i < Z; i++)
    {
        scanf("%d", &c[i]);
    }
    printf("the sum is %d\n", plus6(c));

    printf("6\n");
    int d[Z];
    printf("integers? ");
    for (int i = 0; i < Z; i++)
    {
        scanf("%d", &d[i]);
    }
    printf("the sum is %d\n", plusn(d, Z));

    printf("7\n");
    int e[Z];
    printf("integers? ");
    for (int i = 0; i < Z; i++)
    {
        scanf("%d", &e[i]);
    }
    for (int i = 1; i <= Z; i++)
    {
        printf("the sum of the first %d elements is %d\n", i, plusn(e, i));
    }

    printf("8\n");
    int f[Z], g[Z];
    printf("f? ");
    for (int i = 0; i < Z; i++)
        scanf("%d", &f[i]);
    printf("g? ");
    for (int i = 0; i < Z; i++)
        scanf("%d", &g[i]);
    printf("the product is %d\n", vectormult(f, g));

    printf("9\n");
    int h[Z], j[Z];
    printf("h? ");
    for (int i = 0; i < Z; i++)
        scanf("%d", &h[i]);
    printf("j? ");
    for (int i = 0; i < Z; i++)
        scanf("%d", &j[i]);
    printf("the product is %d\n", vectormult2(h, j));

    printf("10\n");
    float k;
    int l;
    printf("base? ");
    scanf("%f", &k);
    printf("exponent? ");
    scanf("%d", &l);
    printf("the result is %f\n", powr(k, l));

    printf("11\n");
    float m;
    int n;
    printf("base? ");
    scanf("%f", &m);
    printf("exponent? ");
    scanf("%d", &n);
    printf("the result is %f\n", powr2(m, n));

    printf("12\n");
    int o;
    printf("sum up to? ");
    scanf("%d", &o);
    printf("the sum is %d\n", sumn(o));

    printf("13\n");
    char string[100];
    printf("string? ");
    scanf("%s", &string[0]);
    printf("length is %d\n", mystrlen(string));

    printf("14\n");
    char string1[100] = "you should not see this printed 1";
    char string2[100] = "you should not see this printed 2";
    printf("string? ");
    scanf("%s", &string1[0]);
    mystrcpy(string1, string2);
    printf("string1=\"%s\"", string1);
    printf("string2=\"%s\"", string2);
}

void print_binary(unsigned int u)
{
    // start with the most significant bit (31)
    for (int i = 31; i >= 0; i--)
    {
        if (u & (1 << i))
            printf("1");
        else
            printf("0");
        // or: printf("%c", ’0’ + ((u & (1 << i)) != 0));
    }
}
void print_binary(unsigned int u)
{
    for (int i = 31; i >= 0; i--)
        if (u & (1 << i))
            printf("1");
        else
            printf("0");
}
unsigned int read_binary(void)
{
    char s[32];
    unsigned int u;
    printf("32-bit binary number? ");
    // start with the most significant bit (31)
    for (int i = 31; i >= 0; i--)
    {
        // use " %c" to skip spaces
        scanf(" %c", &s[i]);
        if (s[i] >= '0' && s[i] <= '1')
        {
            u = 2 * u + s[i] - '0';
        }
        else
        {
            printf("error: ’%c’ is not a binary digit\n", s[i]);
        }
    }
    return u;
}
void operators()
{
    // << is a shift bit left operator
    // >> is a shift bit right operator

    // & binqary AND operator
    // | binary OR operator
    // ^ binary XOR operator
    // ~ binary NOT operator

    for (int i = 0; i < 32; i++)
        printf("%010u\n", 1 << i);

    int u;
    printf("number? ");
    scanf("%u", &u);
    for (int i = 0; i < 32; i++)
    {
        if (u & (1 << i))
            printf("bit %d is 1\n", i);
    }

    int v;
    printf("number? ");
    scanf("%u", &v);
    print_binary(v);
    printf("\n");

    unsigned int w = read_binary();
    print_binary(w);
    printf("\n");
    print_binary(~w);
    printf("\n");

    // Write a program that asks for two 32-bit unsigned binary numbers and prints their bitwise AND, OR,
    // and exclusive OR.
    unsigned int u1, u2;
    u1 = read_binary();
    u2 = read_binary();
    print_binary(u1);
    printf(" & ");
    print_binary(u2);
    printf(" = ");
    print_binary(u1 & u2);
    printf("\n");
    print_binary(u1);
    printf(" | ");
    print_binary(u2);
    printf(" = ");
    print_binary(u1 | u2);
    printf("\n");
    print_binary(u1);
    printf(" ^ ");
    print_binary(u2);
    printf(" = ");
    print_binary(u1 ^ u2);
    printf("\n");
}

void advacned_char_input()
{
    char c;
    printf("characters? ");
    while (1)
    {
        scanf("%c", &c); // or c = getchar();
        printf("’%c’\n", c);
    }

    char d;
    printf("one line? ");
    do
    {
        scanf("%c", &d); // or c = getchar();
        printf("%c", d);
    } while (d != '\n');

    char e;
    printf("one line? ");
    printf("\"");
    do
    {
        scanf("%c", &e);
        printf("%c", e);
    } while (e != '\n');
    printf("\"\n");
    // the above version is not right as it would print a \n trailing

    char e1;
    int first = 1;
    printf("one line? ");
    do
    {
        scanf("%c", &e1); // or c = getchar();
        if (first)
            printf("\"");
        first = 0;
        if (e1 != '\n')
            printf("%c", e1);
    } while (e1 != '\n');
    printf("\"\n");

    char f;
    do
    {
        printf("one line? ");
        int first = 1;
        do
        {
            scanf("%c", &f); // or c = getchar();
            if (first)
                printf("\"");
            first = 0;
            if (f != '\n')
                printf("%c", f);
        } while (c != '\n');
        printf("\"\n");
    } while (1);

    // check if letter is before or after k in alphabet
    char g;
    printf("one line? ");
    do
    {
        scanf("%c", &g);
        if (g >= 'a' && g <= 'z')
        {
            if (g < 'k')
                printf("’%c’ comes %d letters earlier in the alphabet than ’k’\n", g, 'k' - g);
            if (g > 'k')
                printf("’%c’ comes %d letters later in the alphabet than ’k’\n", g, g - 'k');
        }

    } while (g != '\n');

    // Write a program (called rot1) that reads a line of text and rotates the letters ’a’ to ’z’ in the alpha-
    // bet. Thus ’a’ becomes ’b’, ’b’ becomes ’c’, etc. You have to ensure that ’z’ becomes ’a’.
    char h;
    printf("one line? ");
    do
    {
        scanf("%c", &h); // or c = getchar();
        if (h >= 'a' && h < 'z')
            printf("%c", h + 1);
        else if (h == 'z')
            printf("a");
        else
            printf("%c", h);
    } while (h != '\n');

    char j;
    printf("one line? ");
    do
    {
        scanf("%c", &j); // or c = getchar();
        if (j >= 'a' && j <= 'z')
            printf("%c", 'a' + ((j - 'a') + 1) % 26);
        else
            printf("%c", j);
    } while (j != '\n');
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
        functions();
    }
    else if (n == 6)
    {
        operators();
    }
    else if (n == 7)
    {
        advacned_char_input();
    }
    else
    {
        printf("Invalid input. Please try again.\n");
    }
}
