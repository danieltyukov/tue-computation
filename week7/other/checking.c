#include <stdio.h>
#include <stdlib.h>

struct student
{
    int age;
    double gpa;
    char grade;
};

typedef char user[25];

typedef struct
{
    int age;
    double gpa;
    char grade;
} student2;

int main()
{

    // Pointers
    int var = 10;
    printf("var: %p\n", &var);
    printf("var: %d\n", var);

    int *pvar = &var;
    printf("pvar: %p\n", pvar);  // whats stored pvar: address of var
    printf("pvar: %p\n", &pvar); // address of pvar
    printf("pvar: %d\n", *pvar); // where is the adress inside pvar pointing to

    printf("------------------\n");

    // N dimensional array:
    // [arrays in array][vals in arrays of array]
    int numGrid[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // numGrid[0][1] = 2
    printf("%d\n", numGrid[0][1]);

    printf("------------------\n");

    // Structs (Dictionaries)
    // custom data type
    struct student student1;
    student1.age = 19;
    student1.gpa = 3.4;
    printf("%d\n", student1.age);

    printf("------------------\n");

    // Typedef - giving data type a nickname
    // char user1[25] = "Bro";
    user userr1 = "Bro";

    // struct student stu1 = {19, 3.4};
    // printf("%d\n", stu1.age);

    // no need to use struct keyword
    student2 stu2 = {20, 5.0};
    printf("%f\n", stu2.gpa);
}