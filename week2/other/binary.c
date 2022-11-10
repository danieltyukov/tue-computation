#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int u;
    printf("number? ");
    // undefined binary
    scanf("%u", &u);
    for (int i = 0; i < 32; i++)
    {
        // binary representation
        if (u & (1 << i))
            printf("bit %d is 1\n", i);
    }
}