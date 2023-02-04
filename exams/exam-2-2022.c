#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXINPUT 30
#define MAXROWS 12

typedef struct _row_t_ {
    int nrElements;
    int *elements;
} row_t;

void printMatrix(row_t matrix[MAXROWS]) {
    printf("Matrix:\n");
    for (int i = 0; i < MAXROWS; i++) {
        if (matrix[i].nrElements != 0) {
            printf("Row %d - ", i);
            for (int n = 0; n < matrix[i].nrElements; n++) {
                printf("%d ", matrix[i].elements[n]);
            }
            printf("\n");
        }
    }
}

int nrRows(row_t matrix[MAXROWS]) {
    int numberOfRows = 0;
    for (int i = 0; i < MAXROWS; i++) {
        if (matrix[i].nrElements != 0) {
            numberOfRows++;
        }
    }
    return numberOfRows;
}

void insertRows(row_t matrix[MAXROWS], int nrElements, int row[]) {
    int numberOfRows = nrRows(matrix);
    
    matrix[numberOfRows].nrElements = nrElements;
    matrix[numberOfRows].elements = (int*) malloc(nrElements * sizeof(int));
    
    for (int i = 0; i < nrElements; i++) {
        matrix[numberOfRows].elements[i] = row[i];
    }
}

void swapRows(row_t matrix[MAXROWS], int a, int b) {
    row_t temp = matrix[a];
    // temp.nrElements = matrix[a].nrElements;
    // temp.elements = matrix[a].elements; 
    // For the above you would probably need to malloc and free stuff don't waste time on that
    matrix[a] = matrix[b];
    matrix[b] = temp;
}

void bubbleSort(row_t matrix[MAXROWS]) {
    int numberOfRows = nrRows(matrix);
    int swaps = 0;
    int pastSwaps = 0;;
    
    for (int i = 0; i < numberOfRows - 1; i++) {
        for (int j = 0; j < numberOfRows - 1 - i; j++) {
            if (matrix[j].nrElements > matrix[j+1].nrElements) {
                swapRows(matrix, j, j + 1);
                printf("Swapped row %d and %d\n", j, j+1);
                swaps++;
            }
        }  
        if (swaps != pastSwaps) {
            printf("And another swap\n");
        }
        pastSwaps = swaps;
    }
}

int columnSum(row_t matrix[MAXROWS], int col) {
    int numberOfRows = nrRows(matrix);
    int sum = 0;
    for (int i = 0; i < numberOfRows; i++) {
        if (matrix[i].nrElements > col) {
            sum += matrix[i].elements[col];
        }
    }
    return sum;
}

void deleteRow(row_t matrix[MAXROWS], int row) {
    int numberOfRows = nrRows(matrix);

    // Place all rows behind the deleted row, one index lower
    // This way is probably not the smartest. But it works.
    for (int i = row; i < numberOfRows; i++) { 
        free(matrix[i].elements);
        matrix[i].elements = NULL;
        matrix[i].nrElements = 0;
        if (i < numberOfRows -1) {
            matrix[i].elements = (int*) malloc(matrix[i+1].nrElements * sizeof(int));
            matrix[i].nrElements = matrix[i+1].nrElements;
            for (int j = 0; j < matrix[i+1].nrElements; j++) {
                matrix[i].elements[j] = matrix[i+1].elements[j];
            }
        }
    }
}

// I don't remember the name of this task, and no one asked
void idkRows(row_t matrix[MAXROWS], int row_1, int row_2) {
    int numberOfRows = nrRows(matrix);
    int nrElRow1 = matrix[row_1].nrElements;
    int nrElRow2 = matrix[row_2].nrElements;


    // Merge the rows in to a new row, with row_1 being first than row_2
    int nrElementsSum = nrElRow1 + nrElRow2;
    int tempRow[nrElementsSum];
    int adjustedIndex = 0;
    
    for (int i = 0; i < nrElementsSum; i++) {
        if (i < nrElRow1) {
            tempRow[i] = matrix[row_1].elements[i];
        } else {
            adjustedIndex = i - nrElRow1;
            printf("i: %d a: %d\n", i, adjustedIndex);
            tempRow[i] = matrix[row_2].elements[adjustedIndex];
        }
    }
    
    insertRows(matrix, nrElementsSum, tempRow);

    if (nrElRow1 < nrElRow2) {
        deleteRow(matrix, row_1);
    }
    
    else if (nrElRow1 > nrElRow2) {
        deleteRow(matrix, row_2);
    }
    
    else if (nrElRow1 == nrElRow2) {
        deleteRow(matrix, row_2);
    }
    
}

int main() {
    char cmd;
    row_t matrix[MAXROWS] = {0, NULL};
    
    int row[MAXINPUT];
    int newNrElements = 0;
    int newRow = 0;
    int newRow2 = 0;
    int newCol = 0;
    
    do {
        printf("Command? ");
        scanf(" %c", &cmd);
        int numberOfRows = nrRows(matrix);

        switch(cmd) {
            case 'a': {
                printf("Rows? ");
                scanf("%d %d", &newRow, &newRow2);
                if (newRow >= 0 && newRow2 >= 0 && newRow < numberOfRows && newRow2 < numberOfRows) {
                    idkRows(matrix, newRow, newRow2);
                } else {
                    printf("Invalid row(s)\n");
                }
                break;
            }
            case 'd':
            {
                printf("Delete row? ");
                scanf(" %d", &newRow);
                if (newRow >= 0 && newRow < numberOfRows) {
                    deleteRow(matrix, newRow);
                } else {
                    printf("Invalid row\n");
                }
                break;
            }
            case 'c':
            {
                printf("Column? ");
                scanf(" %d", &newCol);
                printf("The sum of column %d is %d\n", newCol, columnSum(matrix, newCol));
                break;
            }
            case 's':
            {
                bubbleSort(matrix);
                break;
            }
            case 'n':
            {
                printf("Number of row(s) %d\n", numberOfRows);
                break;
            }
            case 'p':
            {
                printMatrix(matrix);
                break;
            }
            case 'i':
            {
                printf("nrElements? ");
                scanf(" %d", &newNrElements);
                if (newNrElements > 0) {
                    printf("elements? ");
                    for(int i = 0; i < newNrElements; i++) {
                        scanf(" %d", &row[i]);
                    }
                    insertRows(matrix, newNrElements, row);
                } else {
                    printf("Not enough rows\n");
                }
                break;
            }
            
            case 'q':
            {
                printf("Bye!\n");
                for (int i  = 0; i < numberOfRows; i++) {
                    free(matrix[i].elements);
                }
                break;
            }
            
            default:
            {
                printf("Unknown command '%c'\n", cmd);
                break;
            }
        }
    } while(cmd != 'q');
    return 0;
}