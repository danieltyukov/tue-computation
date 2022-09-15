// THIS FILE IS FOR INDIVIDUAL TESTS.

#include <stdio.h>
#include <stdlib.h>
// strcpy and strlen would need library string.h:
#include <string.h>

void stringReverseByCopy()
{
    // initial 8 characters
    char str[8] = "0123456";
    // declared reversed empty array
    char reverse[8];
    // len = 7 -- counts from 0
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        reverse[(len - 1) - i] = str[i];
        // len - 1 -- to ensure final value is always \0 and make sure starts from right to left
        // then goes 7-0, 7-1, 7,2 ...
        // Continues until all values from str assigned to reverse
        printf("Loop %d Reverse: %c\n", i, reverse[i]);
    }

    // assign to final position \0 which is 0 in ASCII
    reverse[len] = '\0';
    // copies allfrom reverse to str
    strcpy(str, reverse);
    printf("%s\n", str);
}

void stringReverseInPlace()
{
    // initial 8 characters
    char str[] = "0123456";
    // len = 7 -- counts from 0
    int len = strlen(str);
    // shorter loop to avoid swapping twice
    // directly swaps values from both ends
    for (int i = 0; i < len / 2; i++)
    {
        // value from left
        char swap = str[i];
        // value from right gets assigned to left
        str[i] = str[len - 1 - i];
        // value from left gets assigned to right
        str[len - 1 - i] = swap;
    }
    printf("%s\n", str);
}

int main(void)
{
    int choice;

    printf("Which program would you like to run? ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        stringReverseByCopy();
    }
    else if (choice == 2)
    {
        stringReverseInPlace();
    }
}