#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

#include "predefined.h"

void copyEntry(entry_t concordance[], entry_t *c1, entry_t *c2)
{

    if (c1->word != NULL)
        free(c1->word);

    if (c2->word)
    {

        c1->word = (char *)malloc((strlen(c2->word) + 1) * sizeof(char));

        strcpy(c1->word, c2->word);
    }

    else
        c1->word = NULL;

    for (int i = 0; i < MAXINDEX; i++)
    {

        c1->indices[i] = c2->indices[i];

        c2->indices[i] = -1;
    }
}

void addWord(entry_t concordance[], char *word)
{

    int i;

    int j;

    if (concordance[MAXWORDS - 1].word != NULL)
        return;

    for (i = 0; i < MAXWORDS; i++)
    {

        if (concordance[i].word && !strcmp(word, concordance[i].word))
            return;
    }

    for (j = MAXWORDS - 1; j >= 0; j--)
    {

        entry_t *c1 = &concordance[j];

        entry_t *c2 = &concordance[j + 1];

        if (c1->word != NULL)
        {

            if (strcmp(word, c1->word) > 0)
                break;

            copyEntry(concordance, c2, c1);
        }
    }

    if (concordance[j + 1].word != NULL)
        free(concordance[j + 1].word);

    concordance[j + 1].word = (char *)malloc((strlen(word) + 1) * sizeof(char));

    strcpy(concordance[j + 1].word, word);
}

void addIndex(entry_t concordance[], char *word, int index)
{

    for (int i = 0; i < MAXWORDS; i++)
    {

        entry_t *c = &concordance[i];

        if (!c->word)
            break;

        if (!strcmp(c->word, word))
        {

            for (int j = 0; j < MAXINDEX; j++)
            {

                if (c->indices[j] == -1)
                {

                    c->indices[j] = index;

                    return;
                }
            }
        }
    }

    printf("Word %s not found\n", word);
}

void printConcordance(entry_t concordance[])
{

    int cnt = 0;

    for (int i = 0; i < MAXWORDS; i++)
    {

        entry_t *c = &concordance[i];

        if (c->word == NULL)
            break;

        cnt++;

        if (cnt == 1)
            printf("Concordance\n");

        printf("%10s:", c->word);

        for (int j = 0; j < MAXINDEX; j++)
        {

            if (c->indices[j] == -1)
                break;

            printf(" %d", c->indices[j]);
        }

        printf("\n");
    }

    if (!cnt)
        printf("The concordance is empty\n");
}

void readFile(entry_t concordance[], char *filename, int *index)
{

    int cnt = *index;

    char word[MAXWORDS + 1] = "\0";

    FILE *f = fopen(filename, "r");

    if (!f)
    {

        printf("Cannot open file %s\n", filename);

        return;
    }

    while (1)
    {

        if (fscanf(f, " %s", word) == -1)
            break;

        addWord(concordance, word);

        addIndex(concordance, word, *index);

        *index = *index + 1;
    }

    fclose(f);

    printf("Inserted %d words\n", *index - cnt);
}

void removeWord(entry_t concordance[], char *word)
{

    int i;

    int in = 0;

    for (i = 0; i < MAXWORDS; i++)
    {

        if (!concordance[i].word)
            break;

        if (!strcmp(concordance[i].word, word))
        {

            in = 1;

            free(concordance[i].word);

            concordance[i].word = NULL;

            memset(concordance[i].indices, -1, sizeof(concordance[i].indices));

            break;
        }
    }

    if (!in)
    {

        printf("Word %s not found\n", word);

        return;
    }

    for (; i < MAXWORDS - 1; i++)
    {

        copyEntry(concordance, &concordance[i], &concordance[i + 1]);

        if (!concordance[i].word)
            return;
    }

    concordance[i - 1].word = NULL;

    memset(concordance[i - 1].indices, -1, sizeof(concordance[i - 1].indices));
}

char *findWordAtIndex(entry_t concordance[], int index)
{

    for (int i = 0; i < MAXWORDS; i++)
    {

        for (int j = 0; j < MAXINDEX; j++)
        {

            if (concordance[i].indices[j] == index)
                return concordance[i].word;
        }
    }

    return NULL;
}

void swap(entry_t *c1, entry_t *c2)
{

    entry_t tmp = *c1;

    *c1 = *c2;

    *c2 = tmp;
}

int main(void)

{

    char cmd;

    char word[MAXWORDS + 1] = "\0";

    int index = 0;

    int findex = 0;

    entry_t concordance[MAXWORDS];

    for (int i = 0; i < MAXWORDS; i++)
    {

        concordance[i].word = NULL;

        memset(concordance[i].indices, -1, sizeof(concordance[i].indices));
    }

    do
    {

        printf("Command? ");

        scanf(" %c", &cmd);

        switch (cmd)
        {

        case 'q':

            for (int i = 0; i < MAXWORDS; i++)
            {

                if (concordance[i].word != NULL)
                    free(concordance[i].word);
            }

            printf("Bye!\n");

            break;

        case 'w':

            printf("Word? ");

            scanf(" %s", word);

            addWord(concordance, word);

            break;

        case 'p':

            printConcordance(concordance);

            break;

        case 'i':

            printf("Word index? ");

            scanf(" %s %d", word, &index);

            addIndex(concordance, word, index);

            break;

        case 'r':

            printf("File name? ");

            scanf(" %s", word);

            readFile(concordance, word, &findex);

            break;

        case 'W':

            printf("Word? ");

            scanf(" %s", word);

            removeWord(concordance, word);

            break;

        case 'f':

            printf("Index? ");

            scanf(" %d", &index);

            if (!findWordAtIndex(concordance, index))
                printf("There is no word at index %d\n", index);

            else
                printf("The word at index %d is %s\n", index, findWordAtIndex(concordance, index));

            break;

        default:

            printf("Unknown command '%c'\n", cmd);

            break;
        }
    } while (cmd != 'q');
}