#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// #include "predefined.h" /* Do not delete this line. Do not define row_t yourself. */

#define MAXROWS 11
#define MAXINPUT 12
typedef struct _row_t {
    int nrElements;
    int *elements;
} row_t;

void printMatrix(row_t matrix[MAXROWS]) {
    // check if matrix empty
    if (matrix[0].nrElements == 0) {
        printf("The matrix is empty\n");
        return;
    }
    
    printf("Matrix:\n");
    for (int i = 0; i<MAXROWS; i++) {
        if (matrix[i].nrElements != 0) {
            printf("%2i -", i);
            for (int j = 0; j<matrix[i].nrElements; j++) {
                printf(" %i", matrix[i].elements[j]);
            }
            printf("\n");
        }
        else {
            return;
        }
    }
}

void insertRow(row_t matrix[MAXROWS], int rowElements, int row[]) {
    // check if matrix is full
    if (matrix[MAXROWS-1].nrElements != 0) {
        printf("The matrix is full\n");
        return;
    }
    
    int * temp = (int *)malloc(rowElements*sizeof(int));
    
    for (int i=0; i<MAXROWS; i++) {
        if (matrix[i].nrElements == 0) {
            matrix[i].nrElements = rowElements;
            matrix[i].elements = temp;
            for (int j = 0; j<rowElements; j++) {
                matrix[i].elements[j] = row[j];
            }
            return;
        }
    }
}

int nrRows(row_t matrix[MAXROWS]) {
    int counter = 0;
    for (int i=0; i<MAXROWS; i++) {
        if (matrix[i].nrElements != 0) {
            counter++;
        }
        else {
            return counter;
        }
    }
    return counter;
}

void deleteRow(row_t matrix[MAXROWS], int row) {
    // check if row exists
    if (row<0) {
        printf("Invalid row\n");
        return;
    }
    else {
        for (int i=0; i<MAXROWS; i++) {
            if (matrix[i].nrElements != 0) {
                if (i == row) {
                    matrix[i].nrElements = 0;
                    free(matrix[i].elements);
                    break;
                }
            }
            else {
                printf("Invalid row\n");
                return;
            }
        }
    }
    
    // shift
    row_t temp;
    for (int i = row+1; i<MAXROWS; i++) {
        temp = matrix[i-1];
        matrix[i-1] = matrix[i];
        matrix[i] = temp;
    }
}

int columnSum(row_t matrix[MAXROWS], int column) {
    int sum = 0;
    for (int i=0; i<MAXROWS; i++) {
        if (matrix[i].nrElements != 0) {
            for (int j=0; j<matrix[i].nrElements; j++) {
                if (matrix[i].elements[j] != 0) {
                    if (j == column) {
                        sum = sum+matrix[i].elements[j];
                    }
                }
                else{
                    break;
                }
            }
        }
        else {
            break;
        }
    }
    return sum;
}

void appendRows(row_t matrix[MAXROWS], int row1, int row2) {
    // check if rows exist
    int exist1 = 0;
    int exist2 = 0;
    for (int i = 0; i<MAXROWS; i++) {
        if (matrix[i].nrElements != 0) {
            if (i == row1) {
                exist1 = 1;
                if (row1 == row2) {
                    exist2 = 1;
                }
            }
            else if (i == row2) {
                exist2 = 1;
            }
        }
        else {
            break;
        }
    }
    
    if (exist1 == 0 || exist2 == 0) {
        printf("Invalid row(s)\n");
        return;
    }
    
    // before that concat them and add it as new row
    int rowElements = matrix[row1].nrElements + matrix[row2].nrElements;
    int row[rowElements];

    for (int i = 0; i<rowElements; i++) {
        row[i] = -1;
    }

    for(int i = 0; i<matrix[row1].nrElements; i++) {
        row[i] = matrix[row1].elements[i];
    }
    
    for(int i = 0; i<matrix[row2].nrElements; i++) {
        for (int j = 0; j<rowElements; j++) {
            if (row[j] == -1) {
                row[j] = matrix[row2].elements[i];
                break;
            }
        }
    }
    
    // compare rows delete the one with less nrElements
    if (matrix[row1].nrElements < matrix[row2].nrElements) {
        deleteRow(matrix, row1);
    }
    else if (matrix[row1].nrElements == matrix[row2].nrElements) {
        deleteRow(matrix, row1);
    }
    else {
        deleteRow(matrix, row2);
    }
    
    insertRow(matrix, rowElements, row);
}

void readFile(row_t matrix[MAXROWS], char *fileName) {
    FILE *fp;
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", fileName);
        return;
    }
    
    int column;
    while(fscanf(fp, "%i", &column) != EOF) {
        int sum = columnSum(matrix, column);
        printf("column %i sums to %i\n", column, sum);
    }
}

void sortMatrix(row_t matrix[MAXROWS]) {
    for (int i = 0; i<MAXROWS-1; i++) {
        int pass = 0;
        for (int j = 0; j<MAXROWS-1-i; j++) {
            if (matrix[j].nrElements != 0 && matrix[j+1].nrElements != 0) {
                if (matrix[j].nrElements > matrix[j+1].nrElements) {
                    row_t temp = matrix[j+1];
                    matrix[j+1] = matrix[j];
                    matrix[j] = temp;
                    printf("Swapped %i and %i\n", j, j+1);
                    pass = 1;
                }
            }
        }
        if (pass == 1) {
            printf("Do another pass\n");
        }
    }
}

int main (void)
{
    char cmd;
    row_t matrix[MAXROWS];
    for (int i=0; i<MAXROWS; i++) {
        matrix[i].nrElements = 0;
    }
    
    do {
        printf("Command? ");
        scanf(" %c", &cmd);
        
        switch (cmd) {
            case('q'): {
                for (int i = 0; i<MAXROWS; i++) {
                    if (matrix[i].nrElements != 0) {
                        free(matrix[i].elements);
                    }
                    else {
                        break;
                    }
                }
                printf("Bye!\n");
                break;
            }
            case('p'): {
                printMatrix(matrix);
                break;
            }
            case('i'): {
                int rowElements;
                printf("Number of elements? ");
                scanf(" %i", &rowElements);
                if (rowElements<=0) {
                    printf("Row must contain at least one element\n");
                    break;
                }
                
                int row[rowElements];
                
                printf("Elements? ");
                for (int i = 0; i<rowElements; i++) {
                    scanf(" %i", &row[i]);
                }
                
                insertRow(matrix, rowElements, row);
                
                break;
            }
            case('n'): {
                int num = nrRows(matrix);
                printf("The matrix contains %i rows\n", num);
                break;
            }
            case('d'): {
                int row;
                printf("Row? ");
                scanf(" %i", &row);
                deleteRow(matrix, row);
                break;
            }
            case('c'): {
                int column;
                printf("Column? ");
                scanf(" %i", &column);
                if (column < 0) {
                    printf("Invalid column\n");
                    break;
                }
                int sum = columnSum(matrix, column);
                printf("Column %i sums to %i\n",column, sum);
                break;
            }
            case('a'): {
                int row1;
                int row2;
                printf("Rows? ");
                scanf(" %i %i", &row1, &row2);
                if (row1 < 0 || row2 < 0) {
                    printf("Invalid row(s)\n");
                    break;
                }
                appendRows(matrix, row1, row2);
                break;
            }
            case('r'): {
                char filename[100];
                printf("Filename? ");
                scanf(" %s", filename);
                readFile(matrix, filename);
                break;
            }
            case('s'): {
                sortMatrix(matrix);
                break;
            }
            default: {
                printf("Unknown command '%c'\n", cmd);
                break;
            }
        }
    } while(cmd!='q');
}