#include <stdio.h>

int main(void)
{
    FILE *fh; 
    char filename[100];
    int c;
    printf("file name? ");
    fscanf(stdin, "%s", filename); // stdin - stanadard input for reading a file

    fh = fopen(filename, "r"); // r - read mode

    if (fh==NULL){
        fprintf(stdout, "cannot open %s\n", filename);
        return;
    }

    c = getc(fh);
    while ( c!=EOF)
    {
        putc(c,stdout);
        c = getc(fh);
    }
    fclose(fh);
}