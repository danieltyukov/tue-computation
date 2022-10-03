#include <stdio.h>
#include <string.h>

#define LENGTH 100

void printString(char string[])
{
    for (int i = 0; i < LENGTH; i++)
    {
        if (string[i] == '\0')
        {
            printf("\\0");
        }
        else
        {
            printf("%c", string[i]);
        }
    }
    printf("\n");
}

void insertName(char *startPos[], int *nrNames, char newName[])
{

    int i = 0;
    while (newName[i] != '\0')
    {
        startPos[*nrNames][i] = newName[i];
        i++;
    }
    startPos[*nrNames][i] = '\0';
    startPos[*nrNames + 1] = startPos[*nrNames] + i + 1;

    *nrNames = *nrNames + 1;
}

void printNames(char names[], char *startPos[], int nrNames)
{
    for (int i = 0; i < nrNames; i++)
    {
        printf("startPos[%d]=%02d length=%02d string=\"%s\"\n", i, (int)(startPos[i] - names), (int)strlen(startPos[i]) + 1, startPos[i]);
    }
}

int totalLength(char *startPos[], int nrNames)
{
    int totalLength = 0;
    for (int i = 0; i < nrNames; i++)
    {
        totalLength += strlen(startPos[i]) + 1;
    }
    return totalLength;
}

int lookupNamePos(char names[], char *startPos[], int nrNames, char name[])
{
    int index = -1;
    for (int i = 0; i < nrNames; i++)
    {
        if (strcmp(startPos[i], name) == 0)
        {
            // if the index of the name in names[] is higher than the current index
            // then update the index
            if (startPos[i] - names > index)
            {
                index = startPos[i] - names;
            }
        }
    }
    return index;
}

void removeName(char *startPos[], int *nrNames, char remName[])
{
    // Example
    // startPos = ["one", "two", "three", "four"]
    // removeName("two")
    // startPos = ["one", "four", "three"]

    int flag = 0;
    int index = 0;
    for (int i = 0; i < *nrNames; i++)
    {
        if (strcmp(startPos[i], remName) == 0)
        {
            flag = 1;
            break;
        }
        index++;
    }
    if (flag == 1)
    {
        startPos[index] = startPos[*nrNames - 1];
        startPos[*nrNames - 1] = startPos[*nrNames];
        startPos[*nrNames] = NULL;
        *nrNames = *nrNames - 1;
    }
}

void swapNames(char *startPos[], int i, int j)
{
    char *temp = startPos[i];
    startPos[i] = startPos[j];
    startPos[j] = temp;
}

void insertionSortNames(char *startPos[], int nrNames)
{
    for (int i = 1; i < nrNames; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (strcmp(startPos[j], startPos[j - 1]) < 0)
            {
                swapNames(startPos, j, j - 1);
            }
        }
    }
}

void recoverNames(char names[], char *startPos[], int *nrNames)
{
    for (int i = 0; i < LENGTH; i++)
    {
        // if the name is not \0
        if (names[i] != '\0')
        {
            // if the name is not in startPos[]
            if (lookupNamePos(names, startPos, *nrNames, &names[i]) == -1)
            {
                // print that the name is garbage
                printf("Name \"%s\" starts at %d and is garbage\n", &names[i], i);

                // recover the name by adding it to startPos[] from names[] with its original start position
                startPos[*nrNames] = &names[i];
                *nrNames = *nrNames + 1;
            }
            else
            {
                // print that the name is not garbage
                printf("Name \"%s\" starts at %d and is not garbage\n", &names[i], i);
            }

            // move i to the next name
            i += strlen(&names[i]);
        }
    }
}

int main(void)
{
    char cmd;

    char names[LENGTH] = {0};
    char name[LENGTH] = {0};
    int nrNames = 0;
    char *startPos[LENGTH] = {0};
    startPos[0] = &names[0];

    // task 1
    // print next line
    // strcpy(names, "Asterix");
    // printString(names);

    do
    {
        printf("Command? ");
        scanf(" %c", &cmd);
        switch (cmd)
        {
        case 'q':
        {
            printf("Bye!\n");
            break;
        }
        case 'p':
        {
            printString(names);
            break;
        }
        case 'i':
        {
            printf("Name? ");
            scanf("%s", name);
            insertName(startPos, &nrNames, name);
            break;
        }
        case 'n':
        {
            printNames(names, startPos, nrNames);
            break;
        }
        case 'e':
        {
            printf("Total length is %d\n", totalLength(startPos, nrNames));
            break;
        }
        case 'l':
        {
            printf("Name? ");
            scanf("%s", name);
            int pos = lookupNamePos(names, startPos, nrNames, name);
            printf("\"%s\" has index %d\n", name, pos);
            break;
        }
        case 'r':
        {
            printf("Name? ");
            scanf("%s", name);
            removeName(startPos, &nrNames, name);
            break;
        }
        case 's':
        {
            int i, j;
            printf("Indices? ");
            scanf("%d %d", &i, &j);
            swapNames(startPos, i, j);
            break;
        }
        case 'o':
        {
            insertionSortNames(startPos, nrNames);
            break;
        }
        case 'v':
        {
            recoverNames(names, startPos, &nrNames);
            break;
        }
        default:
        {
            printf("Unknown command '%c'\n", cmd);
            break;
        }
        }
    } while (cmd != 'q');
}