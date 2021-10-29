#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int value;
    struct NODE *next;
}*front = NULL, *rear = NULL;

void PUSH ()
{
    struct NODE *temp = (struct NODE*) malloc (sizeof (struct NODE));
    int num;
    printf ("Enter Value to be added: ");
    scanf ("%d", &num);
    temp->value = num;
    if (front == NULL)
    {
        temp->next = NULL;
        front = temp;
    }
    else
    {
        rear -> next = temp;
    }
    rear = temp;
    printf ("New node added...\n");
}

void POP ()
{
    if (front == NULL)
    {
        printf ("\nQUEUE UNDERFLOW\n");
    }
    else if (front -> next == NULL)
    {
        rear -> next = NULL;
        rear = front = NULL;
        printf ("Existing rear node deleted...\n");
    }   
    else
    {
        front = front -> next;
        printf ("Existing rear node deleted...\n");
    }
    
}

void TRAVERSE ()
{
    struct NODE *temp = front;
    if (front == NULL)
        printf ("Queue Empty...\n");
    else
    {
        printf ("Values are: ");
        while (temp != rear)
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