#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXWORDS 10
#define MAXLENGTH 30

int nrWords(char *dict[]) {
    int counter = 0;
    // num of strings stored in array
    for (int i = 0; i<MAXWORDS; i++) {
        if (dict[i] != NULL) {
            counter++;
        }
    }
    return counter;
}

void addWord(char *dict[], char word[]) {
    
    // if full: dictionary is full
    if (dict[MAXWORDS-1] != NULL) {
        printf("The dictionary is full\n");
        return;
    }
    
    // adds string word to dict
    char * wordVal = (char *)malloc(strlen(word)+1*sizeof(char));
    strcpy(wordVal, word);
    
    for (int i = 0; i<MAXWORDS; i++) {
        if (dict[i] == NULL) {
            dict[i] = wordVal;
            return;
        }
    }
}

void printDict(char *dict[]) {
    // if empty
    if (dict[0] == NULL) {
        printf("The dictionary is empty.\n");
        return;
    }
    
    // prints strings in array
    printf("Dictionary:\n");
    for (int i = 0; i<MAXWORDS; i++) {
        if (dict[i] != NULL) {
            printf("- %s\n", dict[i]);
        }
        else {
            return;
        }
    }
}

int findWord(char *dict[], char word[]) {
    // return -1 if not exist, return first occurance otherwise
    int index = -1;
    for (int i = 0; i<MAXWORDS; i++) {
        if (dict[i] != NULL) {
            if (strcmp(dict[i], word) == 0) {
                index = i;
                break;
            }
        }
        else {
            return index;
        }
    }
    return index;
}

void removeWord(char *dict[], char word[]) {
    int index = 0;
    // if word does not exist
    for (int i = 0; i<MAXWORDS; i++) {
        if (dict[i] != NULL) {
            if (strcmp(dict[i], word) == 0) {
                index = i;
                break;
            }
        }
        else {
            printf("The word \"%s\" is not in the dictionary.\n", word);
            return;
        }
    }
    
    // removes first occurance of word
    free(dict[index]);
    dict[index] = NULL;
    
    for (int i = index+1; i<MAXWORDS; i++) {
        if (dict[i] != NULL) {
            dict[i-1] = dict[i];
            dict[i] = NULL;
        }
        else {
            break;
        }
    }
    return;
}

void swapWords(char *dict[], char word1[], char word2[]) {
    int index1 = -1;
    int index2 = -1;
    // check if at least 1 word is missing
    for (int i = 0; i<MAXWORDS; i++) {
        if (dict[i] != NULL) {
            if (strcmp(dict[i], word1) == 0) {
                index1 = i;
                break;
            }   
        }
        else {
            break;
        }
    }
    
    for (int i = 0; i<MAXWORDS; i++) {
        if (dict[i] != NULL) {
            if (strcmp(dict[i], word2) == 0) {
                index2 = i;
                break;
            }   
        }
        else {
            break;
        }
    }

    if (index1 == -1 || index2 == -1) {
        printf("Cannot swap words. At least one word is missing in the dictionary.\n");
        return;
    }
    
    char * temp;
    temp = dict[index1];
    dict[index1] = dict[index2];
    dict[index2] = temp;
}

int longestWord(char *dict[], int from) {
    int longIndex = -1;
    int currentLength = 0;
    // check if empty or if from is greater than amount of words
    if (dict[from] == NULL)
    {
        return longIndex;
    }
    
    for (int i = from; i<MAXWORDS; i++) {
        if (dict[i] != NULL) {
            if (strlen(dict[i])>currentLength) {
                currentLength = strlen(dict[i]);
                longIndex = i;
            }
        }
        else {
            break;
        }
    }
    return longIndex;
}

void sortDict(char *dict[], int sortedUntil) {
    int longestIndex = sortedUntil;
    // orders by decreasing length
    // recursive
    if (sortedUntil+1 == MAXWORDS) {
        return;
    }
    
    // find longest index
    for (int i = sortedUntil+1; i<MAXWORDS; i++) {
        if (dict[i]!=NULL) {
            if (strlen(dict[longestIndex])<strlen(dict[i])) {
                longestIndex=i;
            }
        }
        else {
            break;
        }
    }
    
    char * temp = dict[sortedUntil];
    dict[sortedUntil] = dict[longestIndex];
    dict[longestIndex] = temp;
    
    if (longestIndex != sortedUntil) {
        printf("swapped %i and %i\n", longestIndex, sortedUntil);
    }
    return sortDict(dict, sortedUntil+1);
}

int main (void)
{
    char cmd;
    char * dict[MAXWORDS];
    for (int i = 0; i<MAXWORDS; i++) {
        dict[i] = NULL;
    }
    char word[MAXLENGTH];
    char word2[MAXLENGTH];
    
    do {
        printf("Command [qnapfrslo]? ");
        scanf(" %c", &cmd);
        
        switch(cmd) {
            case('q'):
            {
                printf("Bye!\n");
                for (int i = 0; i<MAXWORDS; i++) {
                    if (dict[i] != NULL) {
                        free(dict[i]);
                    }
                }
                break;
            }
            case ('n'):
            {
                int nr = nrWords(dict);
                printf("The dictionary contains %i words.\n", nr);
                break;
            }
            case ('a'):
            {
                printf("Word? ");
                scanf(" %s", word);
                addWord(dict, word);
                break;
            }
            case ('p'):
            {
                printDict(dict);
                break;
            }
            case('f'):
            {
                printf("Word? ");
                scanf(" %s", word);
                int index = findWord(dict, word);
                printf("The index of \"%s\" is %i.\n", word, index);
                break;
            }
            case('r'):
            {
                printf("Word? ");
                scanf(" %s", word);
                removeWord(dict, word);
                break;
            }
            case('s'):
            {
                printf("First word? ");
                scanf(" %s", word);
                printf("Second word? ");
                scanf(" %s", word2);
                swapWords(dict, word, word2);
                break;
            }
            case('l'): 
            {
                int lengthIndex = longestWord(dict, 0);
                if (lengthIndex != -1) {
                    printf("The longest word in the dictionary is \"%s\".\n",dict[lengthIndex]);
                }
                break;
            }
            case('o'):
            {
                sortDict(dict, 0);
                break;
            }
            default: 
            {
                printf("Unknown command '%c'\n", cmd);
                break;
            }
        }
        
    } while (cmd!='q');
}