#include <stdio.h>
#include <stdlib.h>
#define LENGTH 30

void task12();
void task3();
void options();
void printArray();
void printString();
void readLine();

void insertChar(char *, char, int);
void replaceChars(char *, char *, char);
void stringReorder(char *, int, int);

int findFirstOccurrence(char *, char);
int readInt(char *, int);

// declaring constant array lengths
char inputString[LENGTH];
char inputChar[LENGTH];
char inputOccurrence[LENGTH];
char inputCharacter[LENGTH];
char inputPosition[LENGTH];

char inputReplace[LENGTH];
char inputReplaceWith[LENGTH];

char inputIndex1[LENGTH];
char inputIndex2[LENGTH];

int main()
{
    // you can uncomment these tasks to play arounf with task 1-3
    // task12();
    // task3();

    options();
}

void task12()
{
    char string1[12] = "hello";
    char string2[12] = "hello\n";
    char string3[12] = "hello\n\0you\n";
    char string4[12] = "0123456789AB";

    // put the arrays in a list
    char *stringList[4] = {string1, string2, string3, string4};

    // list size
    int size = sizeof(stringList) / sizeof(char *);
    // size of none 0 string - 4
    // printf("size: %d", size);

    for (int i = 0; i < size; i++)
    {
        int length = sizeof(string1) / sizeof(char);
        // size of full array - 12
        // printf("length: %d", length);
        printArray(stringList[i], length);
    }

    for (int i = 0; i < size; i++)
    {
        printString(stringList[i]);
    }
}

void task3()
{
    char inputString[LENGTH];
    while (1)
    {
        printf("String? ");
        readLine(inputString, LENGTH);
        printArray(inputString, LENGTH);
        printString(inputString);
    }
}

void options()
{
    do
    {
        printf("Command? ");
        readLine(inputChar, LENGTH);
        switch (inputChar[0])
        {

        case 'q':
            printf("Bye!\n");
            break;

        case 'p':
            printf("The current string is: ");
            printString(inputString);
            break;

        case 'a':
            printf("The current array is: ");
            printArray(inputString, LENGTH);
            break;

        case 's':
            printf("Please enter a string? ");
            readLine(inputString, LENGTH);
            break;

        case 'o':
            printf("Find first occurrence of which character? ");
            readLine(inputOccurrence, LENGTH);
            int index = findFirstOccurrence(inputString, inputOccurrence[0]);
            printf("The first occurrence of '%c' is at index %d\n", inputOccurrence[0], index);
            break;

        case 'i':
            printf("Insert which character? ");
            readLine(inputCharacter, LENGTH);
            printf("At what index? ");
            readLine(inputPosition, LENGTH);
            int finalIndex = readInt(inputPosition, LENGTH);
            insertChar(inputString, inputCharacter[0], finalIndex);
            break;

        case 'r':
            printf("Replace which characters? ");
            readLine(inputReplace, LENGTH);
            printf("with which character? ");
            readLine(inputReplaceWith, LENGTH);
            replaceChars(inputString, inputReplace, inputReplaceWith[0]);
            break;

        case 'R':
            printf("Please enter index 1? ");
            readLine(inputIndex1, LENGTH);
            printf("Please enter index 2? ");
            readLine(inputIndex2, LENGTH);

            int index1 = readInt(inputIndex1, LENGTH);
            int index2 = readInt(inputIndex2, LENGTH);

            stringReorder(inputString, index1, index2);
            break;

        default:
            printf("Unknown command '%c'\n", inputChar[0]);
            break;
        }
    } while (inputChar[0] != 'q');
}

void printArray(char a[], int length)
{
    printf("[");
    for (int i = 0; i < length; i++)
    {
        if (a[i] == '\0')
        {
            printf("\\0");
        }
        else if (a[i] == '\n')
        {
            printf("\\n");
        }
        else
        {
            printf("%c", a[i]);
        }
        if (i < length - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}

void printString(char str[])
{
    printf("\"");
    int i = 0;
    while (str[i] != '\0')
    {
        putchar(str[i]);
        i++;
    }
    printf("\"");
    printf("\n");
}

void readLine(char str[], int length)
{
    int i = 0;
    char c;
    while ((c = getchar()) != '\n')
    {
        if (i < length - 1)
        {
            str[i] = c;
            i++;
        }
    }
    str[i] = '\0';
}

int findFirstOccurrence(char str[], char aChar)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == aChar)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int readInt(char str[], int length)
{
    int i = 0;
    int result = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i] - '0');
        }
        else
        {
            break;
        }
        i++;
    }
    return result;
}

void insertChar(char str[], char aChar, int index)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    while (i >= index)
    {
        str[i + 1] = str[i];
        i--;
    }
    str[index] = aChar;
}

void replaceChars(char str[], char fromString[], char toChar)
{
    int i = 0;
    while (str[i] != '\0')
    {
        int j = 0;
        while (fromString[j] != '\0')
        {
            if (str[i] == fromString[j])
            {
                str[i] = toChar;
            }
            j++;
        }
        i++;
    }
}

void stringReorder(char str[], int index1, int index2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char substring1[LENGTH];
    char substring2[LENGTH];
    char substring3[LENGTH];
    while (str[i] != '\0')
    {
        if (i < index1)
        {
            substring1[j] = str[i];
            j++;
        }
        else if (i < index2)
        {
            substring2[k] = str[i];
            k++;
        }
        else
        {
            substring3[i - index2] = str[i];
        }
        i++;
    }
    substring1[j] = '\0';
    substring2[k] = '\0';
    substring3[i - index2] = '\0';
    i = 0;
    j = 0;
    k = 0;
    while (substring3[i] != '\0')
    {
        str[i] = substring3[i];
        i++;
    }
    while (substring2[j] != '\0')
    {
        str[i] = substring2[j];
        i++;
        j++;
    }
    while (substring1[k] != '\0')
    {
        str[i] = substring1[k];
        i++;
        k++;
    }
    str[i] = '\0';
}
