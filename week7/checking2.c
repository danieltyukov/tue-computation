#include <stdio.h>
#include <stdlib.h>

// malloc - heap memory

// int *ptr = (int*)malloc(4) // allocate 4 bytes of memory

int main()
{
    int i, n;
    printf("Enter the num of ints: ");
    scanf("%d", &n); // & because we need the address

    int *ptr = (int *)malloc(n * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory unavailable.");
        exit(1);
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter an integer: ");
        // storing into the address the ptr provides us
        scanf("%d", ptr + i); // ptr is malloc so already gives us the address
        // + i
        // memory 1000 + 0 = 1000
        // memory 1000 + 1 = 1004 -- the next address
    }
    for (i = 0; i < n; i++)
    {
        // *() where is that address inside ptr e.g 1000 pointing to
        printf("%d \n", *(ptr + i));
    }
    return 0;
}