#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// #include "predefined.h" /* Do not delete this line. Do not define row_t yourself. */

typedef struct _product_t {
    char *product;
    float price;
} product_t;

product_t * newDatabase(product_t *database, int *dbSize, int newSize) {

    // clean previous database
    if (*dbSize != 0) {
        for (int i = 0; i<*dbSize; i++) {
            free(database[i].product);
        }
        free(database);
    }

    if (newSize != 0) {
        database = (product_t *)malloc(newSize*sizeof(product_t));
    }
    *dbSize = newSize;

    for (int i = 0; i<*dbSize; i++) {
        database[i].product = NULL;
        database[i].price = -1;
    }

    return database;
}

void addProduct(product_t *database, int dbSize, char *product, float price) {
    // malloc min size of product and use that to store in database.product
    // we add +1 to strlen because it wont return the full size with the final \0 variable
    char *temp = (char *)malloc((strlen(product)+1)*sizeof(char));
    strcpy(temp, product);

    // check if database full
    if ((dbSize == 0) || (database[dbSize-1].product != NULL)) {
        printf("The database is full\n");
        free(temp);
        return;
    }

    // check if such product already exists
    // add the product to the first NULL in order
    for (int i = 0; i<dbSize; i++) {
        if (database[i].product == NULL) {
            database[i].product = temp;
            database[i].price = price;
            break;
        }
        else {
            if (strcmp(database[i].product, product) == 0) {
                printf("Product is already in the database\n");
                free(temp);
                return;
            }
        }
    }

    // Sort alphabetically
    product_t swap;
    for (int i = 0; i<dbSize-1; i++) {
        for (int j =0; j<dbSize-1-i; j++) {
            if (database[j].product != NULL && database[j+1].product != NULL) {
                if (strcmp(database[j].product, database[j+1].product) > 0) {
                    swap = database[j];
                    database[j] = database[j+1];
                    database[j+1] = swap;
                }
            }
        }
    }

}

void printDatabase(product_t *database, int dbSize) {
    for (int i = 0; i<dbSize; i++) {
        if (database[i].product == NULL) {
            break;
        }
        printf("product %10s costs %07.2f\n", database[i].product, database[i].price);
    }
}

void sortOnPrice(product_t *database, int dbSize) {
    product_t swap;
    product_t swap2;
    for (int i = 0; i<dbSize-1; i++) {
        for (int j = 0; j<dbSize-1-i; j++) {
            if (database[j].price != -1 && database[j+1].price != -1) {
                if (database[j].price > database[j+1].price) {
                    swap = database[j];
                    database[j] = database[j+1];
                    database[j+1] = swap;
                }
                else if (database[j].price == database[j+1].price) {
                    if (strcmp(database[j].product, database[j+1].product) > 0) {
                        swap2 = database[j];
                        database[j] = database[j+1];
                        database[j+1] = swap2;
                    }
                }
            }
        }
    }
}

void readFile(product_t *database, int dbSize, char *fileName) {
    char fileProduct[20];
    float filePrice;
    FILE *fp;
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", fileName);
        return;
    }
    else {
        while (fscanf(fp, "%s %f", fileProduct, &filePrice) != EOF) {
            addProduct(database, dbSize, fileProduct, filePrice);
        }
    }
}

product_t * findProduct(product_t *database, int dbSize, char *product, int lower, int upper) {
    // returns pointer to product or NULL if not in db
    // see if equal with middle if not search one half, then half again then other half

    // print: The price of "product" is "price"
    // or
    // print: Product not found

    int mid = (lower+upper)/2;
    printf("find range (%d,%d)\n", lower, upper);

    if (lower > upper) {
        // wrong input
        return NULL;
    }

    if (strcmp(database[mid].product, product) == 0) {
        return &database[mid];
    }
    else if (strcmp(database[mid].product, product) > 0) {
        return findProduct(database, dbSize, product, lower, mid - 1);
    }
    else {
        return findProduct(database, dbSize, product, mid + 1, upper);
    }
}

int countAmountofProductinDB(product_t *database, int dbSize) {
    int counter = 0;
    for (int i = 0; i<dbSize; i++) {
        if (database[i].product != NULL) {
            counter++;
        }
    }
    return counter;
}

int main(void) {
    char cmd;
    product_t * database = NULL;
    int dbSize = 0;

    do {
        printf("Command? ");
        scanf(" %c", &cmd);

        switch(cmd) {
            case 'q':
            {
                printf("Bye!\n");
                if (dbSize != 0) {
                    // erase memory heap of all pointers
                    for (int i = 0; i<dbSize; i++) {
                        free(database[i].product);
                    }
                    free(database);
                }
                break;
            }
            case 'n':
            {
                int newSize = 0;
                printf("Size? ");
                scanf(" %d", &newSize);
                database = newDatabase(database, &dbSize, newSize);
                break;
            }            
            case 'a':
            {
                // one space at the end always must remain empty
                char productName[11];
                float price;

                printf("Product price? ");
                scanf(" %s %f", productName, &price);
                addProduct(database, dbSize, productName, price);
                break;
            }
            case 'p':
            {
                printDatabase(database, dbSize);
                break;
            }
            case 'r':
            {
                char filename[50];
                printf("Filename? ");
                scanf(" %s", filename);
                readFile(database, dbSize, filename);
                break;
            }
            case 's':
            {
                sortOnPrice(database, dbSize);
                break;
            }
            case 'f':
            {
                char productName[11];
                printf("Product? ");
                scanf(" %s", productName);
                int count = countAmountofProductinDB(database, dbSize);
                product_t * location = findProduct(database, dbSize, productName, 0, (count-1));
                if (location != NULL) { 
                    printf("The price of %s is %.2f\n", productName, location->price);
                }
                else {
                    printf("Product not found\n");
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