// dynamic data allocation.
// call (malloc) to ask system for free space to allocate to.
// call (free) to return the space previously allocated.

// sample
#include <stdio.h>
#include <stdlib.h>

// using malloc dynamic data allocation
void mallocStuff()
{
    // here we allocate space of 10 characters
    char *c1 = (char *)malloc(10 * sizeof(char));

    printf("input a character to test: ");
    scanf("%c", c1);

    printf("\nThe character is: %c\n", *c1);

    free(c1);
}

void pointerSwap(int **a, int **b)
{
    int *tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array(int *a, int rows, int columns)
{
    printf("Printing all values :\n");
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
            printf("%p: %d\n", &a[r * columns + c], a[r * columns + c]);
        printf("\n");
    }
    printf("Printing all values (again):\n");
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
            printf("%p: %d\n", (a + r * columns + c), *(a + r * columns + c));
        printf("\n");
    }
}

int main(void)
{
    mallocStuff();

    int x = 1, y = 2;
    // storing the address of x and y in xp and yp
    int *xp = &x, *yp = &y;
    printf("input: %d %d\n", *xp, *yp);
    // pass in a pointer to xp and yp which are pointers to x and y
    pointerSwap(&xp, &yp);
    printf("swap xp&yp: %d %d\n", *xp, *yp);

    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    print_array(&a[0][0], 2, 3);
}