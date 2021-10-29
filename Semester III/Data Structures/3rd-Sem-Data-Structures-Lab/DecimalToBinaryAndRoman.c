/*
Quesiton: Write a C program to convert a binary number to either binary or roman number, as per option selection.
*/

//My Approach/Solution:
#include <stdio.h>

int main()
{
    unsigned long num;
    int selection;
    printf ("Input the Number: ");
    scanf ("%lu", &num);

    printf ("Make Your Selection:\n");
    printf ("1. Convert To Binary\n");
    printf ("2. Convert To Roman\n");
    printf ("> ");
    scanf ("%d", &selection);

    if (selection == 1)
    {
        if (num > 4294967295)
        {
            printf ("This program has the limit of converting decimal of upto 4,294,967,295 only.\n");
        }
        else 
        {
        char bin ['!'];
        unsigned long i;
        for ( i=0; num != 0; ++i)
        {
            bin [i] = (num % 2) + '0';
            num = num / 2;
        }
        bin [i] = '\0';
        printf ("The Binary form is ");
        for (i=i-1; i>0; --i)
            printf ("%c", bin[i]);
        printf ("%c", bin[i]);
        }
    }
    else if (selection == 2)
    {
        if (num > 3999999999)
        {
            printf ("This progeam doesn't support more than 3,999,999,999...");
        }
        else {
            while(num != 0)
        {
            if (num >= 1000000000)
            {
                printf("[M]");
                num -= 1000000000;
            }
            else if (num >= 900000000)
            {
                printf("[C][M]");
                num -= 900000000;
            }
            else if (num >= 500000000)
            {
                printf("[D]");
                num -= 500000000;
            }
            else if (num >= 400000000)
            {
                printf("[C][D]");
                num -= 400000000;
            }
            else if (num >= 100000000)
            {
                printf("[C]");
                num -= 100000000;
            }
            else if (num >= 90000000)
            {
                printf("[X][C]");
                num -= 90000000;
            }
            else if (num >= 50000000)
            {
                printf("[L]");
                num -= 50000000;
            }
            else if (num >= 40000000)
            {
                printf("[X][L]");
                num -= 40000000;
            }
            else if (num >= 10000000)
            {
                printf("[X]");
                num -= 10000000;
            }
            else if (num >= 9000000)
            {
                printf("[I][X]");
                num -= 9000000;
            }
            else if (num >= 5000000)
            {
                printf("[V]");
                num -= 5000000;
            }
            else if (num >= 4000000)
            {
                printf("[I][V]");
                num -= 4000000;
            }
            else if (num >= 1000000)
            {
                printf("[I]");
                num -= 1000000;
            }
            else if (num >= 900000)
            {
                printf("(C)[I]");
                num -= 900000;
            }
            else if (num >= 500000)
            {
                printf("(D)");
                num -= 500000;
            }
            else if (num >= 400000)
            {
                printf("(C)(D)");
                num -= 400000;
            }
            else if (num >= 100000)
            {
                printf("(C)");
                num -= 100000;
            }
            else if (num >= 90000)
            {
                printf("(X)(C)");
                num -= 90000;
            }
            else if (num >= 50000)
            {
                printf("(L)");
                num -= 50000;
            }
            else if (num >= 40000)
            {
                printf("(X)(L)");
                num -= 40000;
            }
            else if (num >= 10000)
            {
                printf("(X)");
                num -= 10000;
            }
            else if (num >= 9000)
            {
                printf("M(X)");
                num -= 9000;
            }
            else if (num >= 5000)
            {
                printf("(V)");
                num -= 5000;
            }
            else if (num >= 4000)
            {
                printf("M(V)");
                num -= 4000;
            }
            else if (num >= 1000)
            {
                printf("M");
                num -= 1000;
            }

            else if (num >= 900)
            {
                printf("CM");
                num -= 900;
            }        

            else if (num >= 500)
            {           
                printf("D");
                num -= 500;
            }

            else if (num >= 400)
            {
                printf("CD");
                num -= 400;
            }

            else if (num >= 100)
            {
                printf("C");
                num -= 100;                       
            }

            else if (num >= 90)
            {
                printf("XC");
                num -= 90;                                              
            }

                else if (num >= 50)
            {
                printf("L");
                num -= 50;                                                                     
            }

            else if (num >= 40)
            {
                printf("XL");           
                num -= 40;
            }

            else if (num >= 10)
            {
                printf("X");
                num -= 10;           
            }

            else if (num >= 9)
            {
                printf("IX");
                num -= 9;                         
            }

            else if (num >= 5)
            {
                printf("V");
                num -= 5;                                     
            }

            else if (num >= 4)
            {
                printf("IV");
                num -= 4;                                                            
            }

            else if (num >= 1)
            {
                printf("I");
                num -= 1;                                                                                   
            }
        }
        }
    }
    return 0;
}
