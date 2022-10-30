#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// #include "predefined.h" // allows utilization of functions in tasks if cant solve
#define MAXWORDS 60
#define MAXINDEX 10
typedef struct _entry_t
{
    char *word;
    int indices[MAXINDEX];
} entry_t;

void addWord(entry_t concurdance[], char *word)
{
    // adds string word to concurdance, store new word with malloc - done
    // if word already in concurdance, do nothing - done
    // if concurdance is full give error: "Concurdance is full" - done

    int i;

    if (concurdance[MAXWORDS - 1].word != NULL)
    {
        printf("Concurdance is full");
        return;
    }

    for (i = 0; i < MAXWORDS; i++)
    {
        if (concurdance[i].word && !strcmp(word, concurdance[i].word))
        {
            // printf("exists");
            return;
        }
    }

    // just need to add word to concurdance with malloc
    // need to find first empty spot in concurdance
    for (i = 0; i < MAXWORDS; i++)
    {
        if (concurdance[i].word == NULL)
        {
            concurdance[i].word = (char *)malloc((strlen(word) + 1) * sizeof(char));
            strcpy(concurdance[i].word, word);
            // return;
            break;
        }
    }

    // using bubble sort, sort the array in alphabetical order
    // includes words and their indices
    int j;
    for (i = 0; i < MAXWORDS - 1; i++)
    {
        for (j = 0; j < MAXWORDS - i - 1; j++)
        {
            if (concurdance[j].word != NULL && concurdance[j + 1].word != NULL)
            {
                if (strcmp(concurdance[j].word, concurdance[j + 1].word) > 0)
                {
                    entry_t temp = concurdance[j];
                    concurdance[j] = concurdance[j + 1];
                    concurdance[j + 1] = temp;
                }
            }
        }
    }

    // for (i = 0; i < MAXWORDS; i++)
    // {
    //     for (j = 0; j < MAXWORDS - i - 1; j++)
    //     {
    //         if (concurdance[j].word != NULL && concurdance[j + 1].word != NULL)
    //         {
    //             if (strcmp(concurdance[j].word, concurdance[j + 1].word) > 0)
    //             {
    //                 char *temp = concurdance[j].word;

    //                 concurdance[j].word = concurdance[j + 1].word;
    //                 concurdance[j + 1].word = temp;
    //             }
    //         }
    //     }
    // }

    return;
}

void printConcordance(entry_t concordance[])
{
    // prints all words in concurdance
    // if empty print "The concordance is empty" - done
    // 10 char right aligned: %10s

    if (concordance[0].word == NULL)
    {
        printf("The concordance is empty\n");
        return;
    }
    printf("Concordance\n");
    for (int i = 0; i < MAXWORDS; i++)
    {
        if (concordance[i].word == NULL)
        {
            return;
        }
        printf("%10s:", concordance[i].word);
        for (int j = 0; j < MAXINDEX; j++)
        {
            if (concordance[i].indices[j] == -1)
            {
                break;
            }
            printf(" %d", concordance[i].indices[j]);
        }
        printf("\n");
    }
}

void addIndex(entry_t concordance[], char *word, int index)
{
    // add index to a word in concordance, using indices array - done
    // if word does not exist in concordance print "Word "word" not found" - done
    // if full just return - done

    if (concordance[MAXWORDS - 1].indices[MAXINDEX - 1] != -1)
    {
        return;
    }

    for (int i = 0; i < MAXWORDS; i++)
    {
        if (concordance[i].word != NULL)
        {
            if (strcmp(concordance[i].word, word) == 0)
            {
                for (int j = 0; j < MAXINDEX; j++)
                {
                    if (concordance[i].indices[j] == -1)
                    {
                        concordance[i].indices[j] = index;
                        return;
                    }
                }
            }
        }
    }
    printf("Word %s not found\n", word);
    return;
}

void readFile(entry_t concordance[], char *filename, int *index)
{
    // inserts the words from a file including the indices from file
    // print amount of words inserted from file
    // error if ile cant be opened: "Cannot open file "no-file" - done
    char word[MAXWORDS + 1] = "\0";

    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("Cannot opn file %s\n", filename);
        fclose(f);
    }

    // check if such file was already added
    int added = 0;
    for (int i = 0; i < MAXWORDS; i++)
    {
        if (concordance[i].word != NULL)
        {
            if (strcmp(concordance[i].word, filename) == 0)
            {
                // printf("File %s already added\n", filename);
                added = 1;
                break;
            }
        }
    }

    // loop until end of file, index = 0-amount of word
    // read each string from file

    if (added = 1)
    {
        // check amount of words in a file
        int count = 0;
        while (fscanf(f, "%s", word) != EOF)
        {
            count++;
        }
        count++;
    }
    else
    {
        int i = 0;
        while (fscanf(f, "%s", word) != EOF)
        {
            addWord(concordance, word);
            addIndex(concordance, word, *index);
            (*index)++;
            i++;
        }
        printf("Inserted %d words\n", i);
    }

    fclose(f);
}

int main()
{
    char cmd;
    entry_t concurdance[MAXWORDS];
    // +1 for the terminating null byte added by scanf
    char word[MAXWORDS + 1] = "\0";

    for (int i = 0; i < MAXWORDS; i++)
    {
        concurdance[i].word = NULL;
        for (int j = 0; j < MAXINDEX; j++)
        {
            concurdance[i].indices[j] = -1;
        }
    }
    do
    {
        printf("Command? ");
        scanf(" %c", &cmd);

        switch (cmd)
        {
        case 'q':
        {

            for (int i = 0; i < MAXWORDS; i++)
            {
                if (concurdance[i].word != NULL)
                {
                    free(concurdance[i].word);
                }
            }

            printf("Bye!\n");
            break;
        }
        case 'w':
        {
            printf("Word? ");
            scanf(" %s", word);
            addWord(concurdance, word);
            // print the word
            // printf("Added word: %s\n", word);
            break;
        }
        case 'p':
        {
            printConcordance(concurdance);
            break;
        }
        case 'i':
        {
            // free word
            int index;
            printf("Word index? ");
            scanf(" %s %d", word, &index);
            addIndex(concurdance, word, index);
            break;
        }
        case 'r':
        {
            int findex = 0;
            printf("File name? ");
            scanf(" %s", word);
            readFile(concurdance, word, &findex);
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