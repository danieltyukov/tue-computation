#include <stdio.h>
#include <stdlib.h>

// global vars
char cmd;
float curr_re, curr_im;
float new_re, new_im;
int n;
void print_cmd_status();
void ask_for_operation();
void print_current_value();
void print_new_value();

// main function
int main()
{

    printf("** Complex Calculator **\n");

    ask_for_operation();

    while (cmd != 'q')
    {
        print_cmd_status();
        ask_for_operation();
    }
    print_cmd_status();
}

// function to print out the cmd status
void print_cmd_status()
{
    if (cmd == 'q')
    {
        print_current_value();
        printf("Bye!\n");
        exit(0);
    }

    else if (cmd == '+' || cmd == '-' || cmd == '*')
    {
        printf("Complex operand? ");
        scanf("%f %f", &new_re, &new_im);
        if (cmd == '+')
        {
            curr_re += new_re;
            curr_im += new_im;
        }
        else if (cmd == '-')
        {
            curr_re -= new_re;
            curr_im -= new_im;
        }
        else if (cmd == '*')
        {
            // multiply two complex numbers
            // use intermediate variables
            // (2 + i) ∗ (2 + i) = 3 + 4i
            float temp_re = curr_re * new_re - curr_im * new_im;
            float temp_im = curr_re * new_im + curr_im * new_re;
            curr_re = temp_re;
            curr_im = temp_im;
        }
        print_current_value();
    }

    else if (cmd == '0')
    {
        curr_re = 0;
        curr_im = 0;
        print_current_value();
    }

    else if (cmd == 'c')
    {
        // replace the current result by its conjugate
        curr_im = -curr_im;
        print_current_value();
    }

    else if (cmd == 'r')
    {
        // raise the current result to the power n >= 0
        // if n == 0, the result is 1 + 0i
        printf("Natural operand? ");
        scanf("%d", &n);

        // Example

        // Current value is 2.000000+1.000000i
        // Natural operand? 2

        // Calculation
        // (2 + i)2 = (2 + i) ∗ (2 + i) = 3 + 4i
        // (3 + 4i)3 = (3 + 4i) ∗ (3 + 4i) ∗ (3 + 4i) = -117 + 44i

        float multiplier_re = curr_re;
        float multiplier_im = curr_im;
        for (int i = 1; i < n; i++)
        {
            float temp_re = curr_re * multiplier_re - curr_im * multiplier_im;
            float temp_im = curr_re * multiplier_im + curr_im * multiplier_re;
            curr_re = temp_re;
            curr_im = temp_im;
        }
        if (n == 0)
        {
            curr_re = 1;
            curr_im = 0;
        }

        print_current_value();
    }

    else if (cmd == 'p')
    {
        // plot current complex number in two dimensional complex plane (x-axis: real part, y-axis: imaginary part)
        // using .
        // for x-axis, -10 to 10 and for y-axis, -10 to 10
        // print ’+’ instead of ’.’ for the origin (0 + 0i) and print ’*’ at the position of the current
        // complex number(if it is in range).If the current complex number is at the origin then print ’*’.
        // print ’|’ for the y-axis and ’-’ for the x-axis.

        for (int i = 10; i >= -10; i--)
        {
            for (int j = -10; j <= 10; j++)
            {
                if (i == 0 && j == 0)
                {
                    if (curr_re == 0 && curr_im == 0)
                    {
                        printf("*");
                    }
                    else
                    {
                        printf("+");
                    }
                }
                else if (i == 0)
                {
                    printf("-");
                }
                else if (j == 0)
                {
                    printf("|");
                }
                else if (i == (int)curr_im && j == (int)curr_re)
                {
                    printf("*");
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }
        print_current_value();
    }

    else
    {
        printf("Invalid command '%c'\n", cmd);
        print_current_value();
    }
}

// function to ask for operation
void ask_for_operation()
{
    printf("Operation [0+-*crpq]? ");
    scanf(" %c", &cmd);
}

// print out the current value
void print_current_value()
{
    // if curr_im is positive have a + sign inside if not have a - sign
    if (curr_im >= 0)
    {
        printf("Current value is %f+%fi\n", curr_re, curr_im);
    }
    else if (curr_im < 0)
    {
        printf("Current value is %f%fi\n", curr_re, curr_im);
    }
}

void print_new_value()
{
    // if curr_im is positive have a + sign inside if not have a - sign
    if (curr_im >= 0)
    {
        printf("New value is %f+%fi\n", new_re, new_im);
    }
    else if (curr_im < 0)
    {
        printf("New value is %f%fi\n", new_re, new_im);
    }
}
