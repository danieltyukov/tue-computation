#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c;
    int first = 1;
    printf("one line? ");
    do
    {
        scanf("%c", &c);
        if (first)
        {
            printf("\"");
        }
        // so the if statement is not called again
        first = 0;

        if (c != "\n")
        {
            printf("%c", c);
        }
    } while (c != "\n");
    printf("\"\n");
}