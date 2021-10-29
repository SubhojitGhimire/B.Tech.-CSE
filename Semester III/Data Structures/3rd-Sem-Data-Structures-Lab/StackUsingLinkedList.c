/*
Question: Write a C program to implement a stack with such operations: PUSH, POP and TRAVERSE.
*/

//My Approach/Solution:
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int value;
    struct NODE *next;
}*top = NULL, *bottom = NULL;

void PUSH ()
{
    struct NODE *temp = (struct NODE*) malloc (sizeof (struct NODE));
    int num;
    printf ("Enter Value to be added: ");
    scanf ("%d", &num);
    temp->value = num;
    if (top == NULL)
    {
        temp->next = NULL;
        bottom = temp;
    }
    else
    {
        temp -> next = top;
    }
    top = temp;
    printf ("New node added...\n");
}

void POP ()
{
    if (top == NULL)
    {
        printf ("\nSTACK UNDERFLOW\n");
    }
    else if (top -> next == NULL)
    {
        top -> next = NULL;
        top = bottom = NULL;
        printf ("Existing top node deleted...\n");
    }   
    else
    {
        top = top -> next;
        printf ("Existing top node deleted...\n");
    }
    
}

void TRAVERSE ()
{
    struct NODE *temp = top;
    if (top == NULL)
        printf ("Stack Empty...\n");
    else
    {
        printf ("Values are: ");
        while (temp != bottom)
        {
            printf (" %d ",temp -> value);
            temp = temp->next;
        }
        printf ("%d\n", temp -> value);
    }
}

int main()
{
    int option;
    while (option != 4)
    {
        printf ("\nSelect the option: ");
        printf ("\n1. PUSH");
        printf ("\n2. POP");
        printf ("\n3. TRAVERSE");
        printf ("\n4. Exit\n\n> ");
        scanf ("%d", &option);
        printf ("\n");

        if(option == 1)
            PUSH ();
        else if (option == 2)
            POP ();
        else if (option == 3)
            TRAVERSE ();
        else if (option == 4)
            break;
        else
            printf ("Invalid Selection... Try Again...\n");
    }      
    return 0;
}
