/*
Question: Write a C program to perform addition and multiplication operations on two unary numbers.
*/

//My Approach/Solution:
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char num1[17], num2[17];
    int i, j;
    int s1, s2, choice;

    printf ("\nUnary Numbers Must Contain only 1s and Should be of 16 bits or less\n");

    printf ("Enter first number: ");
    scanf ("%[^\n]%*c", num1);
    for (s1=1; num1[s1-1] != '\0'; ++s1);

    printf ("Enter second number: ");
    scanf ("%[^\n]%*c", num2);
    for (s2=1; num2[s2-1] != '\0'; ++s2);  

    if ((s1 - 1) > 16 || (s2 - 1) > 16)
    {
        printf ("Either of the two input numbers exceeds 16 bits");
        exit (0);
    }  

    j = (s1 > s2) ? (s1 - 1) : (s2 - 1);
    
    for (i=0; i < j; ++i)
    {
        if (num1 [i] != '1' && i < (s1-1))
        {
            printf ("Either of the two input numbers is not unary");
            exit (0);
        }
        if (num2 [i] != '1' && i < (s2-1))
        {
            printf ("Either of the two input numbers is not unary");
            exit (0);
        }
    }

    printf ("\n\nSelect what function you want to perform with these two unary numbers?\n");
    printf ("1. Summation\n");
    printf ("2. Multiplication\n");
    scanf ("%d", &choice);

    if (choice == 1)
    {
        printf ("\nThe sum is %s%s", num1, num2);
    }
    else if (choice == 2)
    {
        printf ("\nThe product is ");
        for (i=0; i < (s2-1); ++i)
            printf("%s", num1);
    }

    return 0;
}
