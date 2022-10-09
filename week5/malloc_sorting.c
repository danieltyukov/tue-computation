#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 30

struct person
{
    char *name;
    float height;
};

void removeAllPersons(struct person *persons, int nrPersons)
{
    for (int i = 0; i < nrPersons; i++)
    {
        free(persons[i].name);
    }
    free(persons);
}

void printPersons(struct person persons[], int nrPersons, int from, int to)
{
    int print = 0;
    printf("[");
    for (int i = 0; i < nrPersons; i++)
    {
        if (!(persons[i].name == NULL || persons[i].height == 0.0))
        {
            if (print > 0)
            {
                printf(",(\"%s\",%.3f)", persons[i].name, persons[i].height);
            }
            else
            {
                printf("(\"%s\",%.3f)", persons[i].name, persons[i].height);
                print++;
            }
        }
    }
    printf("]\n");
}

void insertPerson(struct person persons[], int nrPersons, int newEntry, char *newName, float newHeight)
{

    if (persons[newEntry].height == 0.0)
    {
        persons[newEntry].name = (char *)malloc((strlen(newName) + 1) * sizeof(char));
        strcpy(persons[newEntry].name, newName);
        persons[newEntry].height = newHeight;
    }
    else
    {
        printf("Entry %i is already occupied by (\"%s\",%.3f)\n", newEntry, persons[newEntry].name, persons[newEntry].height);
    }
}

void maxHeight(struct person persons[], int nrPersons, float *max)
{
    for (int i = 0; i < nrPersons; i++)
    {
        if (persons[i].height > *max)
        {
            *max = persons[i].height;
        }
    }
}

float minHeight(struct person persons[], int nrPersons)
{
    float minT = 0;
    for (int i = 0; i < nrPersons; i++)
    {
        if (minT == 0)
        {
            minT = persons[i].height;
        }
        if (persons[i].height < minT && persons[i].height != 0)
        {
            minT = persons[i].height;
        }
    }
    return minT;
}

void replacePerson(struct person persons[], int nrPersons,
                   int newEntry, char *newName, float newHeight)
{
    if (persons[newEntry].height == 0 && persons[newEntry].name == NULL)
    {
        insertPerson(persons, nrPersons, newEntry, newName, newHeight);
    }
    else
    {
        free(persons[newEntry].name);
        persons[newEntry].name = (char *)malloc((strlen(newName) + 1) * sizeof(char));
        strcpy(persons[newEntry].name, newName);
        persons[newEntry].height = newHeight;
    }
}

void swapPersons(struct person persons[], struct person *a, struct person *b)
{
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct person persons[], int nrPersons, int *swapped)
{
    int swap = 1;
    int j = nrPersons;
    int count = 0;

    while (swap)
    {
        swap = 0;
        for (int i = 1; i < j; i++)
        {
            if (persons[i].height < persons[i - 1].height || (persons[i].height == persons[i - 1].height && strcmp(persons[i].name, persons[i - 1].name) < 0))
            {
                swapPersons(persons, &persons[i], &persons[i - 1]);
                swap = 1;
                count++;
                printf("after swapping: ");
                printPersons(persons, nrPersons, 0, 0);
            }
        }
        j--;
    }
    printf("Swapped %d times\n", count);
}

void merge(struct person persons[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    struct person L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = persons[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = persons[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i].height <= R[j].height)
        {
            persons[k] = L[i];
            i++;
        }
        else
        {
            persons[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        persons[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        persons[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct person persons[], int left, int right)
{
    if (left < right)
    {
        int m = left + (right - left) / 2;

        mergeSort(persons, left, m);
        mergeSort(persons, m + 1, right);

        merge(persons, left, m, right);
    }
}

int main(void)
{
    struct person *persons = NULL;
    int nrPersons = 0;
    char cmd = 0;
    int nrPersonsT = 0;
    float newHeight = 0;
    float newHeightT = 0;
    char newName[LENGTH] = {0};
    int newEntry = 0;
    float max = 0;
    int swapped = 0;

    do
    {

        printf("Command? ");
        scanf(" %c", &cmd);
        switch (cmd)
        {
        case 'q':
        {
            printf("Bye!\n");
            removeAllPersons(persons, nrPersons);
            break;
        }
        case 'n':
        {
            printf("Entries? ");
            scanf("%i", &nrPersonsT);
            removeAllPersons(persons, nrPersons);
            nrPersons = nrPersonsT;
            persons = (struct person *)malloc(nrPersons * sizeof(struct person));
            if (persons == NULL)
            {
                printf("malloc returned NULL");
                break;
            }
            else
            {
                for (int i = 0; i < nrPersons; i++)
                {
                    persons[i].name = NULL;
                    persons[i].height = 0.0;
                }
            }
            break;
        }
        case 'p':
        {
            printPersons(persons, nrPersons, 0, 1);
            break;
        }
        case 'i':
        {

            printf("Index? ");
            scanf("%i", &newEntry);
            printf("Name? ");
            scanf("%s", newName);
            printf("Height? ");
            scanf("%f", &newHeightT);
            if (newHeightT > 0)
            {
                newHeight = newHeightT;
                insertPerson(persons, nrPersons, newEntry, newName, newHeight);
            }
            else
            {
                printf("Height must be larger than zero\n");
            }
            break;
        }
        case 'h':
        {
            printf("Min: %.3f\n", minHeight(persons, nrPersons));
            maxHeight(persons, nrPersons, &max);
            printf("Max: %.3f\n", max);
            printf("Range: %.3f\n", max - minHeight(persons, nrPersons));
            break;
        }
        case 'r':
        {
            printf("Index? ");
            scanf("%i", &newEntry);
            printf("Name? ");
            scanf("%s", newName);
            printf("Height? ");
            scanf("%f", &newHeightT);
            if (newHeightT > 0)
            {
                newHeight = newHeightT;
                replacePerson(persons, nrPersons, newEntry, newName, newHeight);
            }
            else
            {
                printf("Height must be larger than zero\n");
            }
            break;
        }
        case 'b':
        {
            bubbleSort(persons, nrPersons, &swapped);
            break;
        }
        case 'm':
        {
            mergeSort(persons, 0, nrPersons - 1);

            // if height is equal, sort by name
            for (int i = 0; i < nrPersons - 1; i++)
            {
                if (persons[i].height == persons[i + 1].height)
                {
                    if (strcmp(persons[i].name, persons[i + 1].name) > 0)
                    {
                        swapPersons(persons, &persons[i], &persons[i + 1]);
                    }
                }
            }
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