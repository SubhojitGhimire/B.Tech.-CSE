/*
Question: Write a C program to insert new nodes into circular linked list (i.e., firstly create a circular linked list) and also delete a node based on the location provided by the user.
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

int PUSH ()
{
    struct NODE *temp = (struct NODE*) malloc (sizeof (struct NODE));
    int num;
    printf ("Enter Value to be added: ");
    scanf ("%d", &num);
    temp->value = num;
    if (front == NULL)
    {
        front = temp;
    }
    else
    {
        rear -> next = temp;
    }
    temp -> next = front;
    rear = temp;
    printf ("New node added...\n");
    return 0;
}

int POP (int NodePosition)
{
    struct NODE *temp = front;
    for (int i=1; i< (NodePosition-1); ++i)
    {
        temp = temp->next;
    }
    if (NodePosition == 1)
    {
        front=front->next;
        rear -> next = front;
        printf ("Requested Node Deleted\n");
    }
    else if (temp -> next == rear)
    {
        temp -> next = rear -> next;
        rear = temp;
        printf ("Requested Node Deleted\n");
    }
    else
    {
        temp -> next = (temp -> next) -> next;
        printf ("Requested Node Deleted\n");
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
        printf ("%d", temp -> value);
    }
    temp = temp -> next;
    printf (" -> %d\n", temp->value);
}

int main()
{
    int DeleteNodePosition;
    char yn['!'];
    printf ("Firstly Input Nodes.\n");
    do
    {
        PUSH();
        printf ("\nEnter more nodes? y/n...\n>");
        scanf ("%s", &yn);
    } while (strcmpi (yn, "n"));
    
    printf ("Your created list is: ");
    TRAVERSE();

    printf ("Which Node do you wish to delete? Write it's position: ");
    scanf ("%d", &DeleteNodePosition);
    POP (DeleteNodePosition);

    printf ("Your new list is: ");
    TRAVERSE();
     
    return 0;
}
