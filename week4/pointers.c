// general practice
#include <stdio.h>

// if we didnt use pointers here and just passed vars like a,b
// we would be passing copies of the values of a and b
// so the swap function would be swapping the copies
// and the original values of a and b would not be changed
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 1D ARRAY
void print_array(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}

void rev(char s[], int l)
{
    if (l < 2)
        return;
    char tmp = s[0];
    s[0] = s[l - 1];
    s[l - 1] = tmp;
    rev(s + 1, l - 2);
}

void pointer_array()
{
    char str1[] = "hello";
    char str2[] = "";
    char str3[] = "a bit longer";

    char *array_of_pointers[] = {str1, str2, str3, "last string"};

    for (int i = 0; i < 4; i++)
    {
        printf("array[%d]=\"%s\"\n", i, array_of_pointers[i]);
    }
}

#define ENTRIES 4
#define LENGTH 5
int main(void)
{
    int a = 5;
    int *p = &a;
    printf("%i\n", *p);

    int x = 10;
    int y = 20;
    // PASSING POINTERS WITH &
    swap(&x, &y);
    printf("x is %i and y is %i\n", x, y);

    // 1D ARRAY
    int array[5] = {1, 2, 3, 4, 5};
    print_array(array, 5);

    // array of pointers
    pointer_array();

    // 2D ARRAY
    char array_2_d[ENTRIES][LENGTH] = {"1234", "AB", "xyz"};
    for (int i = 0; i < ENTRIES; i++)
        printf("array[%d] = \"%s\"\n", i, array_2_d[i]);
}