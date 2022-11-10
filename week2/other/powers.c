#include <stdio.h>
#include <stdlib.h>

float powr(float b, int e)
{
    if (e < 1)
    {
        printf("2. HERE\n");
        return 1.0;
    }
    printf("1. NO HERE\n");
    // runs the recursive func certain amount of time until it returned 1
    // them does recursion under this call 5 times.
    float powr_e_minus_one = powr(b, e - 1);

    // the amount of times recursive function is run.
    // anything below is executed the amount of times recurssion happened.
    // this part is executed 5 times.
    {
        printf("3. we are here: %f\n", powr_e_minus_one);
        return b * powr_e_minus_one;
    }
}

int main(void)
{
    float b;
    int e;
    printf("base? ");
    scanf("%f", &b);
    printf("exponent? ");
    scanf("%d", &e);
    // b=3 e=5
    // 243
    // 3*3*3*3*3
    printf("the result is %f\n", powr(b, e));
}