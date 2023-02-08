#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXWORDS 60
#define MAXINDEX 10
typedef struct _entry_t {
    char *word;
    int indices[MAXINDEX];
} entry_t;

void addWord(entry_t concordance[], char *word) {
    // check if word already in concord
    for (int i=0; i<MAXWORDS; i++) {
        if (concordance[i].word != NULL) {
            if (strcmp(concordance[i].word, word) == 0) {
                return;
            }
        }
        else {
            break;
        }
    }
    
    // malloc word before adding to concord
    char * temp = (char *)malloc(strlen(word)+1*sizeof(char));
    strcpy(temp, word);
    
    for (int i=0; i<MAXWORDS; i++) {
        if (concordance[i].word == NULL) {
            concordance[i].word = temp;
            // init indices to -1
            for (int j = 0; j<MAXINDEX; j++) {
                concordance[i].indices[j] = -1;
            }
            break;
        }
    }
    
    // sort alphabetically
    for (int i=0; i<MAXWORDS-1; i++) {
        for (int j=0; j<MAXWORDS-1-i; j++) {
            if (concordance[j].word != NULL && concordance[j+1].word != NULL) {
                if (strcmp(concordance[j].word, concordance[j+1].word) > 0) {
                    entry_t swap = concordance[j];
                    concordance[j] = concordance[j+1];
                    concordance[j+1] = swap;
                }
            }
        }
    }
}

void printConcordance(entry_t concordance[]) {
    // check if empty
    if (concordance[0].word == NULL) {
        printf("The concordance is empty\n");
        return;
    }
    printf("Concordance\n"); 
    for (int i=0; i<MAXWORDS; i++) {
        if (concordance[i].word != NULL) {
            printf("%10s:",concordance[i].word);
            for (int j = 0; j<MAXINDEX; j++) {
                if (concordance[i].indices[j] != -1) {
                    printf(" %i",concordance[i].indices[j]);
                }
            }
            printf("\n");
        }
    }
}

void addIndex(entry_t concordance[], char *word, int index) {
    // check if word even exists
    int wordIndex = -1;
    for (int i = 0; i<MAXWORDS; i++) {
        if (concordance[i].word != NULL) {
            if (strcmp(concordance[i].word, word) == 0) {
                wordIndex = i;
                break;
            }
        }
        else {
            printf("Word %s not found\n", word);
            return;
        }
    }
    
    for (int i = 0; i<MAXINDEX; i++) {
        if (concordance[wordIndex].indices[i] == -1) {
            concordance[wordIndex].indices[i] = index;
            break;
        }
    }
}

void readFile(entry_t concordance[], char *filename, int *index) {
    // find largest index in file
    for (int i = 0; i<MAXWORDS; i++) {
        for (int j=0; j<MAXINDEX; j++) {
            if (concordance[i].word != NULL) {
                if (concordance[i].indices[j] > *index) {
                    *index = concordance[i].indices[j];
                }   
            }
            else {
                break;
            }
        }
    }
    
    if (*index != 0) {
        *index = *index+1;
    } 
    
    char wordFile[100];
    int counter = 0;
    // check if file exists
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        return;
    }
    
    while (fscanf(fp, "%s",wordFile)!=EOF) {
        addWord(concordance, wordFile);
        addIndex(concordance, wordFile, *index+counter);
        counter++;
    }
    
    printf("Inserted %i words\n", counter);
}

void removeWord(entry_t concordance[], char *word) {
    int foundIndex = 0;
    for (int i = 0; i<MAXWORDS; i++) {
        if (concordance[i].word != NULL) {
            if (strcmp(concordance[i].word, word) == 0) {
                free(concordance[i].word);
                concordance[i].word = NULL;
                foundIndex = i;
                break;
            }
        }
        else {
            printf("Word %s not found\n",word);
            return;
        }
    }
    
    for (int i = foundIndex+1; i<MAXWORDS-i; i++) {
        if (concordance[i].word != NULL) {
            concordance[i-1] = concordance[i];
            concordance[i].word = NULL;
        }
    }
}

char *findWordAtIndex(entry_t concordance[], int index) {
    char * foundWord = "none";
    for (int i = 0; i<MAXWORDS; i++) {
        if (concordance[i].word != NULL) {
            for (int j = 0; j<MAXINDEX; j++) {
                if (concordance[i].indices[j] == index) {
                    foundWord = concordance[i].word; 
                }
            }
        }
        else {
            break;
        }
    }
    return foundWord;
}

void printOriginalText(entry_t concordance[]) {
    int largestIndex = -1;
    // find largest index
    for (int i = 0; i<MAXWORDS; i++) {
        if (concordance[i].word != NULL) {
            for (int j = 0; j<MAXINDEX; j++) {
                if (concordance[i].indices[j] > largestIndex) {
                    largestIndex = concordance[i].indices[j];
                }
            }
        }
        else {
            break;
        }
    }
    
    if (largestIndex == -1) {
        return;
    }
    
    // loop through continuously until matched then print if not print ?
    int found = 0;
    for (int k=0; k<largestIndex+1; k++) {
        for (int i=0; i<MAXWORDS; i++) {
            if (concordance[i].word != NULL) {
                for (int j = 0; j<MAXINDEX; j++) {
                    if (concordance[i].indices[j] == k) {
                        printf("%s", concordance[i].word);
                        found = 1;
                    }
                }    
            }
        }
        if (found == 0) {
            printf("?");
        }
        found = 0;
        if (k != largestIndex) {
            printf(" ");
        }
    }
    printf("\n");
}

void sortConcordance(entry_t concordance[]) {
    // sort by first index of each word
    // if the largest indice is same or no indices sort alphabetically
    
    for (int i = 0; i<MAXWORDS-1; i++) {
        for (int j = 0; j<MAXWORDS-1-i; j++) {
            if (concordance[j].word != NULL && concordance[j+1].word) {
                if (concordance[j].indices[0] > concordance[j+1].indices[0]) {
                    entry_t temp = concordance[j];
                    concordance[j] = concordance[j+1];
                    concordance[j+1] = temp;
                }
                else if (concordance[j].indices[0] == concordance[j+1].indices[0]) {
                    if (strcmp(concordance[j].word, concordance[j+1].word) > 0) {
                        entry_t temp = concordance[j];
                        concordance[j] = concordance[j+1];
                        concordance[j+1] = temp;
                    }   
                }
            }
        }
    }
    
}

int main (void)
{
    char cmd;
    entry_t concordance[MAXWORDS];
    for (int i=0;i<MAXWORDS;i++) {
        concordance[i].word = NULL;
    }
    char word[100];
    
    do {
        printf("Command? ");
        scanf(" %c", &cmd);
        
        switch(cmd) {
            case('q'):
            {
                printf("Bye!\n");
                for (int i=0; i<MAXWORDS; i++) {
                    free(concordance[i].word);
                }
                break;
            }
            case('w'):
            {
                printf("Word? ");
                scanf(" %s", word);
                addWord(concordance, word);
                break;
            }
            case('p'):
            {
                printConcordance(concordance);
                break;
            }
            case('i'): 
            {
                int index;
                printf("Word index? ");
                scanf(" %s %i", word, &index);
                addIndex(concordance, word, index);
                break;
            }
            case('r'):
            {
                char filename[100];
                int fileIndex = 0;
                printf("File name? ");
                scanf(" %s", filename);
                readFile(concordance, filename, &fileIndex);
                break;
            }
            case('W'):
            {
                printf("Word? ");
                scanf(" %s", word);
                removeWord(concordance, word);
                break;
            }
            case('f'):
            {
                int index;
                printf("Index? ");
                scanf(" %i", &index);
                char * foundWord = findWordAtIndex(concordance, index);
                if (strcmp(foundWord, "none") == 0) {
                    printf("There is no word at index %i\n", index);
                }
                else {
                    printf("The word at index %i is %s\n", index,foundWord);
                }
                break;
            }
            case('o'):
            {
                printOriginalText(concordance);
                break;
            }
            case('s'):
            {
                sortConcordance(concordance);
                break;
            }
            default:
            {
                printf("Unknown command '%c'\n", cmd);
                break;
            }
        }
        
    } while(cmd!='q');
}