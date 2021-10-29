/*
Question: Write a C program to perform addition and multiplication operations on two roman numbers.
*/

//My Approach/Solution:
#include <stdio.h>
#include <string.h>

int ConvertToDecimal (char num[20]);
int convert(char ch);
int ConvertToRoman(int num);

int main ()
{
   char num1 [20], num2[20];
    int selection;

   printf ("\nEnter the first Roman Number (Capitalised Format): ");
   scanf ("%s", num1);
   printf ("\nEnter the second Roman Number (Capitalised Format): ");
   scanf ("%s", num2);

   printf ("\nSelect Operation:\n");
   printf ("1. Addition\n");
   printf ("2. Multiplication\n");
    scanf ("%d", &selection);

   if (selection == 1)
   {
       int addition = ConvertToDecimal (num1) + ConvertToDecimal (num2);
       printf ("\nThe summation of these two input Romans Numbers is ");
       ConvertToRoman (addition);
   }
   else
   {
       int multiplication = ConvertToDecimal (num1) * ConvertToDecimal (num2);
       printf ("\nThe product of these two input Roman Numbers is ");
       ConvertToRoman (multiplication);
   }
    return 0;
}


int ConvertToDecimal (char num[20])
{
    int i = 0, DecNum = 0;

   while(num [i])
   {
      if (convert(num [i]) < 0 )
      {
         printf("\nInvalid Roman Number.\n");
         return 0;
      }
      if((strlen (num) - i ) > 2)
      {
         if(convert(num [i]) < convert(num [i+2]))
         {
            printf("\nInvalid Roman Number.\n");
            return 0;
         }
      }
      if(convert(num [i]) >= convert(num [i+1]))
         DecNum += convert( num [i]);
      else
      {
         DecNum += (convert(num [i+1]) - convert(num [i]));
         ++i;
      }
      ++i;
   }
   return DecNum;
}

int convert(char ch)
{
   int value = 0;

   switch(ch)
   {
      case 'I': value = 1; break;
      case 'V': value = 5; break;
      case 'X': value = 10; break;
      case 'L': value = 50; break;
      case 'C': value = 100; break;
      case 'D': value = 500; break;
      case 'M': value = 1000; break;
      case '\0': value = 0; break;
      default: value = -1;
   }
   return value;
}

int ConvertToRoman(int num)
{
    while(num != 0)
    {

        if (num >= 1000)
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
           printf("c");
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
    return 0;
}
