#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// #include "predefined.h" // allows utilization of functions in tasks if cant solve

int main()
{
    char cmd;

    do
    {
        printf("Command? ");
        scanf("%c", &cmd);

        switch (cmd)
        {
        case 'q':
        {
            printf("Bye!\n");
            break;
        }
        }

    } while (cmd != 'q');
}