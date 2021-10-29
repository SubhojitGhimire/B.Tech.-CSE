#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void ValidityCheck ()
{
    int input[16], product, summation = 0;
    char TempInput;
    printf ("\nENTER THE 16-BIT NUMBER WHOSE VALIDITY YOU WISH TO CHECK:\n> ");
    for (int i=0; i<16; ++i)
    {
        TempInput = getche ();
        input [i] = TempInput - '0';
        if ((i+1) % 4 == 0)
            printf ("\t");
    }

    for (int i = 1; i < 16; i = i+2)
    {
        summation += input [i];
    }
    for (int i = 0; i<15; i = i+2)
    {
        product = input [i] * 2;
        if (product > 9)
            product = (product % 10) + 1;
        summation += product;
    }

    if (! (summation % 10))
        printf ("\nVALID CARD\n");
    else
        printf ("\nINVALID CARD\n");  
}

void GenerateCheckDigit ()
{
    int input[16], product, summation = 0, CheckDigit;
    char TempInput;
    printf ("\nENTER THE FIRST 15-DIGITS OF THE NUMBER YOU WISH TO GENERATE:\n> ");
    for (int i=0; i<15; ++i)
    {
        TempInput = getche ();
        input [i] = TempInput - '0';
        if ((i+1) % 4 == 0)
            printf ("\t");
    }

    for (int i = 1; i < 14; i = i+2)
    {
        summation += input [i];
    }
    for (int i = 0; i<15; i = i+2)
    {
        product = input [i] * 2;
        if (product > 9)
            product = (product % 10) + 1;
        summation += product;
    }

    CheckDigit = ((summation / 10)*10 + 10) - summation;
    input [15] = CheckDigit;
    printf ("\nThe Check Digit is %d", CheckDigit);
    printf ("\nThe Valid Credit Card Number so-formed is ");

    for (int i=0; i<16; ++i)
    {
        printf ("%d", input[i]);
        if ((i+1)%4 == 0)
            printf ("\t");
    }
}

int main()
{
    printf ("##########################\n");
    printf ("#### LUHN ALGORITHM ######\n");
    printf ("##########################\n");
    printf ("\nSelect one of the options: ");
    printf ("\n1. Check Validity of the Credit Card Number");
    printf ("\n2. Generate the check digit");
    printf ("\n3. Exit\n\n> ");
    int option;
    scanf ("%d", &option);
    switch (option)
    {
        case 1: ValidityCheck();
                break;
        case 2: GenerateCheckDigit();
                break;
        default: printf ("Exiting...");
                exit(0);
    }
    return 0;
}