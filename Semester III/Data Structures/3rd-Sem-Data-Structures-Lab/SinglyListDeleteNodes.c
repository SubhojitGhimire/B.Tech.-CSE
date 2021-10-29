/*
Question: Write a C program to delete an item from a desired location from a singly linked list.
*/

//My Approach/Solution:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE
{
    int value, position;
    struct NODE *next;
}*front = NULL, *rear = NULL;

int PUSH (int pos)
{
    struct NODE *temp = (struct NODE*) malloc (sizeof (struct NODE));
    temp->position = pos;
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
    return 0;
}

int POP (int NodePosition)
{
    if (NodePosition == front->position)
    {
        front=front->next;
        printf ("Requested Node Deleted");
    }
    else
    {
        struct NODE *temp = front;
        while (temp != rear)
        {
            if ((temp->next)->position == NodePosition)
            {
                temp->next = (temp->next)->next;
                printf ("Requested Node Deleted");
            }    
            temp = temp->next;
        }
    } 
    return 0;
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
    int DeleteNodePosition, size=0, pos=0;
    char yn['!'];
    printf ("Firstly Input Nodes.\n");
    do
    {
        ++pos; 
        PUSH(pos);
        printf ("\nEnter more nodes? y/n...\n>");
        scanf ("%s", &yn);
    } while (strcmpi (yn, "n"));
    
    printf ("Your created list is: ");
    TRAVERSE();

    printf ("Which Node do you wish to delete? Write its position: ");
    scanf ("%d", &DeleteNodePosition);
    POP (DeleteNodePosition);

    printf ("Your new list is: ");
    TRAVERSE();
     
    return 0;
}
