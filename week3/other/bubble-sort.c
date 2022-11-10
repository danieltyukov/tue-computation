#include <stdio.h>

// swaps numbers next to each other
// loops over array by its length

void bubble_sort(int a[], int length)
{
    for (int i = 0; i < length; i++)
    {
        // here length - 1 - i is same as length - 1 just we make less checks
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// if array sorted stop loop
void optimized_bubblesort(float values[], int size)
{
    int i, swap;
    float tmp;
    do
    {
        swap = 0;
        for (i = 0; i < size - 1; i++)
        {
            if (values[i] > values[i + 1])
            {
                tmp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = tmp;
                swap = 1;
            }
        }
    } while (swap == 1);
}

int main(void)
{
    int a[] = {3, 9, 27, 38, 43, 10, 82};
    int length = sizeof(a) / sizeof(a[0]);
    bubble_sort(a, length);
    for (int i = 0; i < length; i++)
    {
        printf("%i ", a[i]);
    }
    printf("\n");

    float b[] = {3.0, 9.0, 27.0, 38.0, 43.0, 10.0, 82.0};
    int length2 = sizeof(b) / sizeof(b[0]);
    optimized_bubblesort(b, length2);
    for (int i = 0; i < length2; i++)
    {
        printf("%f ", b[i]);
    }
    printf("\n");
}