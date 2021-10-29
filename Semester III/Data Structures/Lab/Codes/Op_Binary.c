#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ConvertToDecimal (char num1 [9], int size);

int main()
{
    char num1[9], num2[9];
    int i, j, choice;
    int s1, s2;

    printf ("\nBinary Numbers Must Contain only 1s and Should be of 8 bits or less\n");

    printf ("Enter first number: ");
    scanf ("%[^\n]%*c", num1);
    for (s1=1; num1[s1-1] != '\0'; ++s1);

    printf ("Enter second number: ");
    scanf ("%[^\n]%*c", num2);
    for (s2=1; num2[s2-1] != '\0'; ++s2);  

    if ((s1 - 1) > 8 || (s2 - 1) > 8)
    {
        printf ("Either of the two input numbers exceeds 8 bits");
        exit (0);
    }  

    j = (s1 > s2) ? (s1 - 1) : (s2 - 1);
    
    for (i=0; i < j; ++i)
    {
        if (num1 [i] != '1' && num1 [i] != '0' && i < (s1-1))
        {
            printf ("Either of the two input numbers is not binary");
            exit (0);
        }
        if (num2 [i] != '1' && num2 [i] != '0'  && i < (s2-1))
        {
            printf ("Either of the two input numbers is not binary");
            exit (0);
        }
    }

    printf ("\n\nSelect what function you want to perform with these two binary numbers\n");
    printf ("1. Summation\n");
    printf ("2. Multiplication\n");
    scanf ("%d", &choice);

    while (choice == 1)
    {
        char add[10];
        int carry=0, a, b, sa = s1-2, sb = s2-2;
        add[9] = '\0';
        for (i = 8; i>=0; --i)
        {
            if (sa < 0)
                a = 0;
            else 
                a = num1 [sa--] - '0';

            if (sb < 0)
                b = 0;
            else 
                b = num2 [sb--] - '0';
                
            if (a+b+carry == 0)
            {
                add[i] = '0';
                carry = 0;
            }
            else if (a+b+carry == 1)
            {
                add[i] = '1';
                carry = 0;
            }
            else if (a+b+carry == 2)
            {
                add[i] = '0';
                carry = 1;
            }
            else
            {
                add[i] = '1';
                carry = 1;
            }
        }
        printf ("\nThe summation of the numbers is %s", add);
        break;
    }

    while (choice == 2)
    {
        int a = ConvertToDecimal (num1, s1-2);
        int b = ConvertToDecimal (num2, s2-2);
        int c = a*b;
        int mul [16];
        for (i=0; i<16; ++i)
        {
            while (c != 0)
            {
                mul [15 - i] = c % 2;
                c = c / 2;
                ++i;
            }
            mul [15 - i] = 0;
        }
        printf ("\nThe product of these two binary numbers is ");
        for (i=0; i<16; ++i)
            printf ("%d", mul [i]);
        break;
    }


    return 0;
}


int ConvertToDecimal (char num1 [9], int size)
{
    int dec=0;
    for (int i=0; i<=size; ++i)
    {
        if (num1[i] == '1')
        {
            dec += pow (2, size - i);
        }
    }
    return dec;
}