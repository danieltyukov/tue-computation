#include <stdio.h>
#include <stdlib.h>

int main(void){
    char s[100] = {NULL};
    char c;
    printf("String? ");
    scanf("%s", s);
    printf("Character? ");
    scanf(" %c", &c);
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            printf("%d\n", i+1);
            return 0;
        }
        i++;
    }
}