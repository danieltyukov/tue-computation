#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Pointers and Addresses
void func1()
{
    int i = 1;
    float f = 2;
    double d = 3;
    printf("i=%d at address %p\n", i, &i);
    printf("f=%f at address %p\n", f, &f);
    printf("d=%e at address %p\n", d, &d);
}

void func2()
{
    int i[3] = {1, 2, 3};
    char c[5] = "hell";
    for (int j = 0; j < 3; j++)
        printf("i[%d]=%d at address %p\n", j, i[j], &i[j]);
    for (int j = 0; j < 5; j++)
        printf("c[%d]=’%c’ at address %p\n", j, c[j], &c[j]);
}

void func3()
{
    int i = 10;
    int *p1 = &i;
    int *p2 = &i;
    printf("i=%d\n", i);
    printf("&i=%p\n", &i);
    printf("p1=%p\n", p1);
    printf("p2=%p\n", p2);
    printf("&p1=%p\n", &p1);
    printf("&p2=%p\n", &p2);
}

void func4()
{
    int i = 10;
    int *p1 = &i;
    int *p2 = &i;
    printf("i=%d\n", i);
    printf("&i=%p\n", &i);
    printf("p1=%p\n", p1);
    printf("p2=%p\n", p2);
    printf("&p1=%p\n", &p1);
    printf("&p2=%p\n", &p2);
    *p1 = 20;
    // or: *p2 = 20;
    printf("i=%d\n", i);
}

void func5()
{
    int a[7] = {7, 6, 5, 4, 3, 2, 1};
    int *p = &a[0];
    for (int i = 0; i < 7; i++)
        printf("a[%d]=%d\n", i, a[i]);
    for (int i = 0; i < 7; i++)
        printf("p=%p+%d=%p a[%d]=%d\n", p, i, p + i, i, *(p + i));
}

// Pointers and Function Arguments

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void func6()
{
    double a = 10, b = 20;
    printf("a=%f b=%f\n", a, b);
    swap(&a, &b);
    printf("a=%f b=%f\n", a, b);
}

int *next_element(int a[10], int i)
{
    // (i+1) % 10 gives the next element, wrapping around the end
    // a[(i+1)%10] is that element in the array
    // &a[(i+1)%10] is the address of that element
    return &a[(i + 1) % 10];
    // alternatively, just work with the address:
    return a + (i + 1) % 10;
}
void func7()
{
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (int i = 0; i < 10; i++)
    {
        int *next = next_element(a, i);
        printf("a[%d]=%d is stored at %p; the next element a[%d]=%d is stored at %p\n",
               i, a[i], &a[i], i, *next, next);
    }
}

int len(char *s)
{
    int l = 0;
    while (*s != '\0')
    {
        l++;
        s++;
    }
    // or: while (*s) { l++; s++; }
    // or: while (*s++) l++;
    return l;
}
void func8()
{
    char s[100] = {'\0'};
    printf("String? ");
    scanf("%s", s);
    // same as scanf("%s", &s[0]);
    printf("len(\"%s\")=%d\n", s, len(s));
}

void rev(char *s)
{
    int l = len(s);
    if (l == 0)
        return;
    char copy[l];
    for (int i = 0; i < l; i++)
        *(copy + l - 1 - i) = *(s + i);
    // now copy the reversed string back into s
    for (int i = 0; i < l; i++)
        *(s + i) = *(copy + i);
}
void func9()
{
    char s[100] = {'\0'};
    printf("String? ");
    scanf("%s", s);
    printf("rev(\"%s\")=", s);
    rev(s);
    printf("%s\n", s);
}

void rev2(char *s)
{
    int l = len(s);
    if (l == 0)
        return;
    char copy[l];
    char *sp = s;
    char *cp = copy + l - 1;
    for (int i = 0; i < l; i++)
    {
        *cp-- = *sp++;
    }
    // now copy the reversed string back into s
    sp = s;
    cp = copy;
    for (int i = 0; i < l; i++)
    {
        *sp = *cp;
        sp++;
        cp++;
        // or: *sp++ = *cp++;
    }
}
void func10()
{
    char s[100] = {'\0'};
    printf("String? ");
    scanf("%s", s);
    printf("rev(\"%s\")=", s);
    rev(s);
    printf("%s\n", s);
}

// SWAPPING USING POINTER VARIABLES - NO RECURSION
//  void rev(char *s)
//  {
//      int l = len(s);
//      for (int i = 0; i < l / 2; i++)
//      {
//          char swap = *(s + i);
//          *(s + i) = *(s + l - 1 - i);
//          *(s + l - 1 - i) = swap;
//      }
//  }
//
// SWAPPING USING POINTER VARIABLES - YES RECURSION
// void rev(char *s, int l)
// {
//     if (l < 2)
//         return;
//     char swap = *s;
//     *s = *(s + l - 1);
//     *(s + l - 1) = swap;
//     rev(s + 1, l - 2);
// }
int main(void)
{
}