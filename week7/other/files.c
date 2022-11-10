#include <stdio.h>

int main(void)
{
    FILE *fh; // pointer to file file type stored, file handle declared
    char filename[100];

    int c;

    printf("file name? ");
    fscanf(stdin, "%s", filename);
    fh = fopen(filename, "r");

    if (fh == NULL)
    {
        fprintf(stdout, "cannot open");
        return;
    }

    c = getc(fh);
    while (c != EOF)
        ;
    {
        putc(c, stdout);
        c = getc(fh);
    }
    fclose(fh);
}