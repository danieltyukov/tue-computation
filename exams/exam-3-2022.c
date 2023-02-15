#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// #include "predefined.h" /* Do not delete this line. Do not define MAXWORDS. */

#include MAXWORDS 11

void printWordList(char *wordList[MAXWORDS]) {
    if (wordList[0] == NULL) {
        return;
    }
    for (int i = 0; i<MAXWORDS; i++) {
        if (wordList[i] != NULL) {
            printf("\"%s\" is referenced from entries %i\n", wordList[i], i);
        }
    }
}

void insertWord(char *wordList[MAXWORDS], char *word) {
    if (wordList[MAXWORDS-1] != NULL) {
        printf("List is full\n");
        return;
    }
    
    char * temp = (char *)malloc((strlen(word)+1)*sizeof(word));
    strcpy(temp, word);
    
    for (int i = 0; i<MAXWORDS; i++) {
        if (wordList[i] == NULL) {
            wordList[i] = temp;
            break;
        }
    }

    for (int i = 0; i<MAXWORDS-1; i++) {
        for (int j = 0; j<MAXWORDS-1-i; j++) {
            if (wordList[j] != NULL && wordList[j+1] != NULL) {
                if (strcmp(wordList[j], wordList[j+1]) > 0) {
                    char * tempWord = wordList[j];
                    wordList[j] = wordList[j+1];
                    wordList[j+1] = tempWord;
                }
            }
        }
    }
}

void vowelChange (char *wordList[MAXWORDS]) {
    if (wordList[0] == NULL) {
        return;
    }
    
    for (int i = 0; i<MAXWORDS; i++) {
        if (wordList[i] != NULL) {
            int wordLength = strlen(wordList[i])+1;
            
            char * word = wordList[i];
            for (int j = 0; j<wordLength; j++) {
                if (word[j] == 'a') {
                    word[j] = 'e';
                }
                else if (word[j] == 'e') {
                    word[j] = 'a';
                }
                else if (word[j] == 'o') {
                    word[j] = 'u';
                }
                else if (word[j] == 'u') {
                    word[j] = 'o';
                }
            }
        }
        else {
            break;
        }
    }
}

void readFile(char *wordList[MAXWORDS], char *fileName) {
    char word[100];
    FILE *fp;
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", fileName);
        return;
    }
    
    while (fscanf(fp, "%s", word) != EOF) {
        insertWord(wordList, word);
    }
}

void bubbleSort(char *wordList[MAXWORDS]) {
    int swapped = 0;
    for (int i = 0; i<MAXWORDS-1; i++) {
        swapped = 0;
        for (int j = 0; j<MAXWORDS-1-i; j++) {
            if (wordList[j] != NULL && wordList[j+1] != NULL) {
                if (strlen(wordList[j]) > strlen(wordList[j+1])) {
                    printf("Swapped %i and %i\n", j, j+1);
                    char * swap = wordList[j];
                    wordList[j] = wordList[j+1];
                    wordList[j+1] = swap;
                    swapped = 1;
                }
            }
        }
        if (swapped == 1) {
            printf("Do another pass\n");
        }
    }
}

void shareWord(char *wordList[MAXWORDS], char *word) {
    int exists = 0;
    for (int i = 0; i<MAXWORDS; i++) {
        if (wordList[i] != NULL) {
            if (strcmp(wordList[i], word) == 0) {
                exists = 1;
                break;
            }
        }
        else {
            break;
        }
    }
    
    if (exists == 0) {
        insertWord(wordList, word);
        return;
    }
}

void deleteWord(char *wordList[MAXWORDS], char *word) {
    
    int exist = 0;
    
    for (int i = 0; i<MAXWORDS; i++) {
        if (wordList[i] != NULL) {
            if (strcmp(wordList[i], word) == 0) {
                exist = 1;
                break;
            }
        }
    }
    
    if (exist == 0) {
        printf("Word not found\n");
        return;
    }
    
    int latestIndex = -1;
    for (int i = 0; i<MAXWORDS; i++) {
        if (wordList[i] != NULL) {
            if (strcmp(wordList[i], word) == 0) {
                latestIndex = i;
            }
        }
        else {
            break;
        }
    }
    
    free(wordList[latestIndex]);
    wordList[latestIndex] = NULL;
    
    for (int i = latestIndex+1; i<MAXWORDS; i++) {
        char * temp = wordList[i-1];
        wordList[i-1] = wordList[i];
        wordList[i] = temp;
    }
}

int main (void)
{
  char cmd;
  char * wordList[MAXWORDS];
  for (int i = 0; i<MAXWORDS; i++) {
      wordList[i] = NULL;
  }
  
  do {
      printf("Command? ");
      scanf(" %c",&cmd);
      switch(cmd) {
          case('q'): {
              for (int i = 0; i<MAXWORDS; i++) {
                  if (wordList[i] != NULL) {
                      free(wordList[i]);
                  }
              }
              printf("Bye!\n");
              break;
          }
          case('p'): {
              printWordList(wordList);
              break;
          }
          case('i'): {
              char word[100];
              printf("Word? ");
              scanf(" %s", word);
              insertWord(wordList, word);
              break;
          }
          case('v'): {
              vowelChange(wordList);
              break;
          }
          case('r'): {
              char fileName[100];
              printf("Filename? ");
              scanf(" %s", fileName);
              readFile(wordList, fileName);
              break;
          }
          case('b'): {
              bubbleSort(wordList);
              break;
          }
          case('s'): {
              char word[100];
              printf("Word? ");
              scanf(" %s", word);
              shareWord(wordList, word);
              break;
          }
          case('d'): {
              char word[100];
              printf("Word? ");
              scanf(" %s", word);
              deleteWord(wordList, word);
              break;
          }
          default: {
              printf("Unknown command '%c'\n",cmd);
              break;
          }
      }
  } while(cmd!='q');
}