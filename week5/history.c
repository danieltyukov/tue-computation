#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HISTORY 6

// with stack its first come last leave - goes to bottom
// with heap its first come first leave - goes to top

int main(void)
{
    char *history[HISTORY] = {NULL};
    char cmd[100];

    do
    {
        printf("Command? ");
        scanf("%s", cmd);

        if (history[HISTORY - 1] != NULL)
        {
            free(history[HISTORY - 1]);
        }

        // now we need to shift our heap
        // if string "ls" is in position 0 now its in position 1
        for (int i = HISTORY - 2; i >= 0; i--)
        {
            history[i + 1] = history[i];
        }

        // now that we moved our heap we fill in the first empty space
        history[0] = (char *)malloc(strlen(cmd));
        strcpy(history[0], cmd);

        if (!strcmp(cmd, "history"))
        {
            for (int i = HISTORY - 1; i >= 0; i--)
            {
                if (history[i] != NULL)
                {
                    printf("%d %s\n", i, history[i]);
                }
            }
        }

    } while (strcmp(cmd, "quit"));
    printf("Bye!\n");
}