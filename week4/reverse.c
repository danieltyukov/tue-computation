#include <stdio.h>
#include <stdlib.h>

int len(char *s){
    int l = 0;
    while (*s != '\0')
    {
        l++;
        s++;
    }
    return l;
}

void rev(char *s, int l)
{
    printf("THE LENGTH NOW IS: %d\n", l);
    if (l<2)
    {
        return;
    }
    // swap init to current s
    char swap = *s;
    // first char becomes last
    *s = *(s+l-1);
    // last char becomes first
    *(s+l-1) = swap;

    rev(s+1, l-2);
}

int main(void)
{
    char s[100] = {NULL};
    // we can also say '\0' instead of NULL
    printf("String? ");
    scanf("%s",s);

    printf("rev(\"%s\")=\n", s);
    int length = len(s);
    // printf(" %d", length);

    rev(s, length);
    printf("%s\n", s);
}