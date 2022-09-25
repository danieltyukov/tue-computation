#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

void print(float matrix[MAXSIZE][MAXSIZE], int rows, int columns, char name)
{
    printf("Matrix %c (%d X %d):\n", name, rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%8.2f", matrix[i][j]);
        }
        printf("\n");
    }
}

int add(float matrixA[MAXSIZE][MAXSIZE], int rowsA, int columnsA,
        float matrixB[MAXSIZE][MAXSIZE], int rowsB, int columnsB,
        float matrixC[MAXSIZE][MAXSIZE], int rowsC, int columnsC)
{
    if (rowsA != rowsB || columnsA != columnsB)
    {
        printf("Dimensions of A & B do not match\n");
        return 1;
    }

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < columnsA; j++)
        {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return 0;
}

int mult(
    float matrixA[MAXSIZE][MAXSIZE], int rowsA, int columnsA,
    float matrixB[MAXSIZE][MAXSIZE], int rowsB, int columnsB,
    float matrixC[MAXSIZE][MAXSIZE], int rowsC, int columnsC)
{

    if (columnsA != rowsB)
    {
        printf("Dimensions of A & B do not match\n");
        return 1;
    }

    // reset Matrix C back to:
    // Matrix C (1 X 1)
    // 0.00
    for (int i = 0; i < rowsC; i++)
    {
        for (int j = 0; j < columnsC; j++)
        {
            matrixC[i][j] = 0;
        }
    }

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < columnsB; j++)
        {
            for (int k = 0; k < columnsA; k++)
            {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return 0;
}

void printRecursive(float matrixA[MAXSIZE][MAXSIZE],
                    int rowsA, int columnsA, int currentRow, int currentColumn)
{
    if (currentRow == rowsA)
    {
        printf("enter printRecursive with current row=%d column=%d\n", currentRow, currentColumn);
        printf("finished the recursion with current row=%d column=%d\n", currentRow, currentColumn);
        return;
    }

    printf("enter printRecursive with current row=%d column=%d\n", currentRow, currentColumn);

    int nextRow = currentRow;
    int nextColumn = currentColumn + 1;

    if (nextColumn == columnsA)
    {
        nextRow = currentRow + 1;
        nextColumn = 0;
    }

    printRecursive(matrixA, rowsA, columnsA, nextRow, nextColumn);

    printf("%8.2f\n", matrixA[currentRow][currentColumn]);
    printf("exit printRecursive with current row=%d column=%d\n", currentRow, currentColumn);
}

int main(void)
{
    char cmd;

    float matrixA[MAXSIZE][MAXSIZE] = {0};
    float matrixB[MAXSIZE][MAXSIZE] = {0};
    float matrixC[MAXSIZE][MAXSIZE] = {0};
    int rowsA = 1;
    int columnsA = 1;
    int rowsB = 1;
    int columnsB = 1;
    int rowsC = 1;
    int columnsC = 1;
    do
    {
        printf("Command? ");
        scanf(" %c", &cmd);
        switch (cmd)
        {
        case 'q':
        {
            printf("Bye!\n");
            break;
        }
        case 'a':
        {
            print(matrixA, rowsA, columnsA, 'A');
            break;
        }

        case 'b':
        {
            print(matrixB, rowsB, columnsB, 'B');
            break;
        }
        case 'c':
        {
            print(matrixC, rowsC, columnsC, 'C');
            break;
        }
        case 't':
        {

            float temp[MAXSIZE][MAXSIZE] = {0};

            for (int i = 0; i < rowsA; i++)
            {
                for (int j = 0; j < columnsA; j++)
                {
                    temp[j][i] = matrixA[i][j];
                }
            }

            for (int i = 0; i < columnsA; i++)
            {
                for (int j = 0; j < rowsA; j++)
                {
                    matrixA[i][j] = temp[i][j];
                }
            }

            int tempRt = rowsA;
            rowsA = columnsA;
            columnsA = tempRt;

            break;
        }
        case 'p':
        {
            // print the elements of matrixA in reverse order
            // using recursion
            printRecursive(matrixA, rowsA, columnsA, 0, 0);
            break;
        }
        case 'm':
        {
        }
        case 'B':
        {
            for (int i = 0; i < rowsA; i++)
            {
                for (int j = 0; j < columnsA; j++)
                {
                    matrixB[i][j] = matrixA[i][j];
                }
            }
            rowsB = rowsA;
            columnsB = columnsA;
            break;
        }
        case 'I':
        {

            int tempR = 1;
            int tempC = 1;

            printf("Size of matrix A (rows columns)? ");
            scanf("%d %d", &tempR, &tempC);

            if (tempR != tempC || tempR > MAXSIZE || tempC > MAXSIZE || tempR < 1 || tempC < 1 || tempR > 10 || tempC > 10)
            {
                printf("Rows & columns must be equal and between 1 and 10\n");
                break;
            }

            for (int i = 0; i < tempR; i++)
            {
                for (int j = 0; j < tempC; j++)
                {
                    if (i == j)
                    {
                        matrixA[i][j] = 1;
                    }
                    else
                    {
                        matrixA[i][j] = 0;
                    }
                }
            }

            rowsA = tempR;
            columnsA = tempC;
            break;
        }
        case 'A':
        {

            int tempRA = 1;
            int tempCA = 1;

            printf("Size of matrix A (rows columns)? ");
            scanf("%d %d", &tempRA, &tempCA);

            if (tempRA > MAXSIZE || tempCA > MAXSIZE || tempRA < 1 || tempCA < 1 || tempRA > 10 || tempCA > 10)
            {
                printf("Rows & columns must be between 1 and 10\n");
                break;
            }

            for (int i = 0; i < tempRA; i++)
            {
                printf("Row %d? ", i);
                for (int j = 0; j < tempCA; j++)
                {
                    scanf("%f", &matrixA[i][j]);
                }
            }

            rowsA = tempRA;
            columnsA = tempCA;
            break;
        }
        case '+':
        {
            int addition = add(matrixA, rowsA, columnsA, matrixB, rowsB, columnsB, matrixC, rowsC, columnsC);
            if (addition == 0)
            {
                rowsC = rowsA;
                columnsC = columnsA;
            }
            break;
        }
        case '*':
        {
            int multiplication = mult(matrixA, rowsA, columnsA, matrixB, rowsB, columnsB, matrixC, rowsC, columnsC);
            if (multiplication == 0)
            {
                rowsC = rowsA;
                columnsC = columnsB;
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