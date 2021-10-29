/*
Question: Write a C program to insert a node into a singly linked list at front, before a node, after a node, and last.
*/

//My Approach/Solution:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void TRAVERSE ()
{
    struct NODE *temp = front;
    if (front == NULL)
        printf ("Queue Empty...\n");
    else
    {
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
    char yn['!'];
    printf ("Firstly Input Nodes.\n");
    do
    {
        PUSH();
        printf ("\nEnter more nodes? y/n...\n>");
        scanf ("%s", &yn);
    } while (strcmpi (yn, "n"));

    printf ("\nYour created Nodes: ");
    TRAVERSE ();

    int option;
    do
    {
        printf ("\nSelect the option: ");
        printf ("\n1. Add New Node at Front");
        printf ("\n2. Add New Node Before an existing Node");
        printf ("\n3. Add New Node After an existing Node");
        printf ("\n4. Add Node at Last");
        printf ("\n5. Exit\n\n> ");
        scanf ("%d", &option);
        printf ("\n");
        if (option==5)
            break;
        struct NODE *newnode = (struct NODE*) malloc (sizeof (struct NODE));
        int num, existing;
        struct NODE *temp = front;

        printf ("Enter Value to be Added: ");
            scanf ("%d", &num);
        newnode->value = num;
        switch (option)
        {
            case 1 :
                    newnode->next = front;
                    front = newnode;
                    break;

            case 2 :
                    printf ("Choose data of existing node: ");
                    scanf ("%d", &existing);
                    while (temp != rear)
                    {
                        if ((temp->next)->value == existing);
                        {
                            newnode->next = (temp->next)->next;
                            temp->next = newnode;
                            break;
                        }
                        temp=temp->next;
                    }
                    break;

            case 3 :
                    printf ("Choose data of existing node: ");
                    scanf ("%d", &existing);
                    while (temp != rear)
                    {
                        if ((temp->next)->value == existing);
                        {
                            newnode->next = ((temp->next)->next)->next;
                            (temp->next)->next = newnode;
                            break;
                        }
                        temp=temp->next;
                    }
                    break;
                    
            case 4 :
                    newnode->next = NULL;
                    rear -> next = newnode;
                    rear = newnode;
                    break;

            default :
                    break;
        }
    }  while (option < 5 && option > 0); 

    printf ("\nYour modified Nodes: ");
    TRAVERSE ();   

    return 0;
}
