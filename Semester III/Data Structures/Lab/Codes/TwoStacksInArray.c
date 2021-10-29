#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int value;
    struct NODE *next;
}*top [2], *bottom [2];

void PUSH (int stack_no)
{
    struct NODE *temp = (struct NODE*) malloc (sizeof (struct NODE));
    int num;
    printf ("Enter Value to be added in Stack %d: ", stack_no + 1);
    scanf ("%d", &num);
    temp->value = num;
    if (top [stack_no] == NULL)
    {
        temp->next = NULL;
        bottom [stack_no] = temp;
    }
    else
    {
        temp -> next = top [stack_no];
    }
    top [stack_no]= temp;
    printf ("New node added in Stack %d...\n", stack_no + 1);
}

void POP (int stack_no)
{
    if (top [stack_no] == NULL)
    {
        printf ("\nSTACK UNDERFLOW\n");
    }
    else if (top [stack_no] -> next == NULL)
    {
        top [stack_no] -> next = NULL;
        top [stack_no] = bottom [stack_no] = NULL;
        printf ("Existing top node deleted in Stack %d...\n", stack_no + 1);
    }   
    else
    {
        top [stack_no] = top [stack_no] -> next;
        printf ("Existing top node deleted in Stack %d...\n", stack_no + 1);
    }
    
}

void TRAVERSE (int stack_no)
{
    struct NODE *temp = top [stack_no];
    if (top [stack_no]== NULL)
        printf ("Stack %d Empty...\n", stack_no + 1);
    else
    {
        printf ("Values in Stack %d are: ", stack_no + 1);
        while (temp != bottom [stack_no]) 
        {
            printf (" %d ",temp -> value);
            temp = temp->next;
        }
        printf ("%d\n", temp -> value);
    }
}

int main()
{
    top [0] = top [1] = bottom [0] = bottom [1] = NULL;
    int option;
    while (option != 7)
    {
        printf ("\nSelect the option: ");
        printf ("\n1. PUSH in Stack I");
        printf ("\n2. POP in Stack I");
        printf ("\n3. TRAVERSE in Stack I");
        printf ("\n4. PUSH in Stack II");
        printf ("\n5. POP in Stack II");
        printf ("\n6. TRAVERSE in Stack II");
        printf ("\n7. Exit\n\n> ");
        scanf ("%d", &option);
        printf ("\n");

        if(option == 1)
            PUSH (0);
        else if (option == 2)
            POP (0);
        else if (option == 3)
            TRAVERSE (0);
        else if(option == 4)
            PUSH (1);
        else if (option == 5)
            POP (1);
        else if (option == 6)
            TRAVERSE (1);
        else if (option == 7)
            break;
        else
            printf ("Invalid Selection... Try Again...\n");
    }      
    return 0;
}