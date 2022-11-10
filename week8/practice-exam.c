#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXWORDS 10
#define MAXLENGTH 30

int nrWords(char *dict[])
{
    int amount = 0;
    for (int i=0; i<MAXWORDS; i++)
    {
        if (dict[i] != NULL)
        {
            amount++;
        }
    }
    return amount;
}

void addWord(char *dict[], char word[])
{
    
    //now we must store that pointer in our pointer array
    
    //check if array full
    if (dict[MAXWORDS-1] != NULL)
    {
        printf("The dictionary is full.\n");
        return;
    }
    
    // varSpace is a pointer to where our word is now stored
    char *varSpace = (char *)malloc(MAXLENGTH*sizeof(char));
    strcpy(varSpace, word);
    
    for (int i=0; i<MAXWORDS; i++)
    {
        if (dict[i] == NULL)
        {
            dict[i] = varSpace;
            return;
        }
    }
    
}

void printDict(char *dict[])
{
    if (dict[0] == NULL){
        printf("The dictionary is empty.\n");
        return;
    }
    
    printf("Dictionary: \n");
    
    for (int i=0; i<MAXWORDS; i++)
    {
        if (dict[i] != NULL)
        {
            printf("- %s\n", dict[i]);
        }
    }
    return;
}

int findWord(char *dict[], char word[])
{
    //strcmp(x,y)
    //x<y return <0
    //x>y return >0
    //x==y return 0
    
    int index = 0;
    
    for (int i=0; i<MAXWORDS; i++)
    {
        if (dict[i] != NULL)
        {
            if (!strcmp(dict[i], word))
            {
                return index;
            }
        }
        index++;
    }
    return -1;
    
}

void removeWord(char *dict[], char word[])
{
    // loop through dict find word  remove it
    // move the rest of the items in dict 1 up
    
    for (int i=0; i<MAXWORDS; i++)
    {
        if (dict[i] != NULL)
        {
            // CHECK
            if (!strcmp(dict[i],word))
            {
                free(dict[i]);
                dict[i] = NULL;
                // now from the i at this specific do shifting
                for (int j=i; j<MAXWORDS-1; j++)
                {
                    dict[j] = dict[j+1];
                }
                dict[MAXWORDS-1] = NULL;
                return;
            }
        }
    }
    printf("The word \"%s\" is not in the dictionary.\n",word);
    return;
    
}

void swapWords(char *dict[], char word1[], char word2[])
{
    //get indexes of the words
    int index1 = findWord(dict,word1);
    int index2 = findWord(dict,word2);
    
    if (index1 == -1 || index2 == -1)
    {
        printf("Cannot swap words. At least one word is missing in the dictionary\n");
        return;
    }
    char *temp[MAXWORDS] = {'\0'};
    
    temp[0] = dict[index1];
    dict[index1] = dict[index2];
    dict[index2] = temp[0];
    return;
}

int longestWord(char *dict[], int from)
{
    // returns index of longest word
    int longestWord = -1;
    int length = 0;
    
    for (int i=from; i<MAXWORDS; i++)
    {
        if (dict[i] != NULL)
        {
            int tmpLength = strlen(dict[i]);
            if (tmpLength > length)
            {
                length = tmpLength;
                longestWord = findWord(dict,dict[i]);
            }
        }
    }
    return longestWord;
}

void sortDict(char *dict[], int sortedUntil)
{
    int i = nrWords(dict);
    
    // empty
    if (i == 0)
    {
        return;
    }
    
    // sortedUntil index = nrWords
    if (sortedUntil == i-1)
    {
        return;
    }
    
    i = longestWord(dict, sortedUntil);
    // if first is smaller than the last
    if (strlen(dict[sortedUntil]) < strlen(dict[i]))
    {
        // we swap it
        swapWords(dict, dict[sortedUntil], dict[i]);
        printf("swapped %d and %d\n", i, sortedUntil);
    }
    sortDict(dict, sortedUntil + 1);
}
   
int main (void)
{
    char cmd;
    char *dict[MAXWORDS] = {'\0'};
    int nrStrings; 
    char word[MAXLENGTH];
    char word1[MAXLENGTH];
    char word2[MAXLENGTH];
    int index;
    
    do {
        printf("Command [qnapfrsLo]? ");
        scanf(" %c",&cmd);
        
        switch(cmd){
            case('q'):
            {
                for (int i=0; i<MAXWORDS; i++)
                {
                    if (dict[i] != NULL)
                    {
                        free(dict[i]);
                    }
                }
                printf("Bye!\n");
                break;
            }
            
            case('n'):
            {
                nrStrings = nrWords(dict);
                printf("The dictionary contains %d words.\n", nrStrings);
                break;
            }
            
            case('a'):
            {
                printf("Word? ");
                scanf(" %s",word);
                addWord(dict,word);
                break;
            }
            
            case ('p'):
            {
                printDict(dict);
                break;
            }
            
            case ('f'):
            {
                printf("Word? ");
                scanf(" %s", word);
                index = findWord(dict,word);
                printf("The index of \"%s\" is %d.\n",word,index);
                break;
            }
            
            case ('r'):
            {
                printf("Word? ");
                scanf(" %s", word);
                removeWord(dict, word);
                break;
            }
            
            case ('s'):
            {
                printf("First word? ");
                scanf(" %s", word1);
                printf("Second word? ");
                scanf(" %s",word2);
                swapWords(dict,word1,word2);
                break;
            }
            
            case ('l'):
            {
                int from = 0;
                index = longestWord(dict,from);
                if (index != -1)
                {
                    // printf("%d\n", index);
                    printf("The longest word in the dictionary is \"%s\".\n",dict[index]);
                }
                break;
            }
            
            case ('o'):
            {
                int sortedUntil = 0;
                sortDict(dict, sortedUntil);
                break;
            }
            
            default:
            {
                printf("Unknown command \'%c\'\n", cmd);
                break;
            }
            
        }
    } while(cmd !='q');
}