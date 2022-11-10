#include <stdio.h>

char imm_signChecker(float curr_imm)
{
    if (curr_imm<0)
    {
        return '-';
    }
    return '+';
}

void printVal(float curr_re, float curr_imm)
{
    char imm_sign = imm_signChecker(curr_imm);
    if (imm_sign == '-')
    {
        printf("Current value is %f%fi\n", curr_re,curr_imm);
    }
    else
    {
        printf("Current value is %f%c%fi\n", curr_re,imm_sign,curr_imm);
    }
}

int main(void)
{
    char cmd;
    float curr_re = 0.0;
    float curr_imm = 0.0;
    float new_re = 0.0;
    float new_imm = 0.0;
    int nat_o = 0;
    
    printf("** Complex Calculator **\n");
    
    do
    {
        printf("Operation [0+-*crpq]? ");
        scanf(" %c", &cmd);
        
        switch(cmd)
        {
            case ('q'):
            {
                printVal(curr_re, curr_imm);
                printf("Bye!\n");
                break;
            }
            
            case ('+'):
            {
                printf("Complex operand? ");
                scanf(" %f %f", &new_re,&new_imm);
                curr_re+=new_re;
                curr_imm+=new_imm;
                printVal(curr_re, curr_imm);
                break;
            }
            
            case ('-'):
            {
                printf("Complex operand? ");
                scanf(" %f %f", &new_re,&new_imm);
                curr_re-=new_re;
                curr_imm-=new_imm;
                printVal(curr_re, curr_imm);
                break;
            }
            
            case ('0'):
            {
                curr_re = 0.0;
                curr_imm = 0.0;
                printVal(curr_re, curr_imm);
                break;
            }
            
            case ('c'):
            {
                curr_imm*=-1.0;
                printVal(curr_re, curr_imm);
                break;
                
            }
            
            case ('*'):
            {
                printf("Complex operand? ");
                scanf(" %f %f", &new_re,&new_imm);
                float tmp_re = curr_re * new_re - curr_imm * new_imm;
                float tmp_imm = curr_re * new_imm + curr_imm * new_re;
                curr_re = tmp_re;
                curr_imm = tmp_imm;
                printVal(curr_re, curr_imm);
                break;
            }
            
            case ('r'):
            {
                printf("Natural operand? ");
                scanf(" %d", &nat_o);
                float multiplier_re = curr_re;
                float multiplier_imm = curr_imm;
                
                for (int i=1; i<nat_o; i++)
                {
                    float temp_re = curr_re * multiplier_re - curr_imm * multiplier_imm;
                    float temp_imm = curr_re * multiplier_imm + curr_imm * multiplier_re;
                    curr_re = temp_re;
                    curr_imm = temp_imm;
                }
                
                if (nat_o == 0)
                {
                    curr_re = 1;
                    curr_imm = 0;
                }
                
                printVal(curr_re, curr_imm);
                break;
            }
            
            case ('p'):
            {
                
                
                for (int i = 10; i>=-10; i--)
                {
                    for (int j = -10; j<=10; j++)
                    {
                        if ((curr_re >= j && curr_re < j+1) && (curr_imm >= i && curr_imm < i+1)) printf("*");
                        else if (i == 0 && j==0) printf("+");
                        else if (i == 0 && j!=0) printf("-");
                        else if (j == 0 && i!=0) printf("|");
                        else printf("."); 
                        
                    }
                    printf("\n");
                }
                printVal(curr_re, curr_imm);
                break;
            }
            
            default:
            {
                printf("Invalid command \'%c\'\n", cmd);
                printVal(curr_re, curr_imm);
                break;
            }
        }
        
    } while (cmd!='q');
}
