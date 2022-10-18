#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Pointers into Arrays
char *find_pos(char *s, char c)
{
    while (*s != '\0' && *s != c)
        s++;
    return s;
}

int main(void)
{
    char letters[53] = {'\0'};
    char letter;
    for (int i = 0; i < 26; i++)
    {
        letters[i] = 'a' + i;
        letters[i + 26] = 'A' + i;
    }
    // note that we moved these pi initialisations
    // because letters needs to be initialised first!
    char *p1 = find_pos(letters, 'a');
    char *p2 = find_pos(letters, 'n');
    char *p3 = find_pos(letters, 'A');
    char *p4 = find_pos(letters, 'N');
    printf("letter? ");
    scanf(" %c", &letter);
    printf("the start address of the array is %p\n", letters);
    printf("the array index of '%c' in the array is %ld\n", letter, find_pos(letters, letter) - letters);
    printf("the address of '%c' in the array is %p\n", letter, find_pos(letters, letter));
    printf("p1=%p strlen(%s)=%ld\n", p1, p1, strlen(p1));
    printf("p2=%p strlen(%s)=%ld\n", p2, p2, strlen(p2));
    printf("p3=%p strlen(%s)=%ld\n", p3, p3, strlen(p3));
    printf("p4=%p strlen(%s)=%ld\n", p4, p4, strlen(p4));
}