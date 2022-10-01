#include <stdio.h>
#include <string.h>

void rev(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    printf("%s\n", s);
}

int main(void)
{
    char s[100];
    printf("Enter a string: ");
    // including spaces
    scanf("%[^\n]s", s);
    rev(s);
}