/*
Question: Write a C program to convert a decimal number to its corresponding binary number.
*/

//My Approach/Solution:
#include <stdio.h>

int main()
{
    unsigned long num;
    printf ("Input the Number: ");
    scanf ("%lu", &num);
    char bin ['!'];
    unsigned long i;
    for (i=0; num != 0; ++i)
    {
        bin [i] = (num % 2) + '0';
        num = num / 2;
    }
    bin [i] = '\0';
    printf ("The Binary form is ");
    for (i=i-1; i>0; --i)
        printf ("%c", bin[i]);
    printf ("%c", bin[i]);
    
    /* for (i=i-1; i>=0; --i) { printf ("%c", bin[i]); } gives garbage output; no idea why*/
    
    return 0;
}
