#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE
{
    int value;
    struct NODE *next, *prev;
}*front = NULL, *rear = NULL;

void PUSH ()
{
    struct NODE *temp = (struct NODE*) malloc (sizeof (struct NODE));
    int num;
    printf ("Enter Value to be added: ");
    scanf ("%d", &num);
    temp -> value = num;
    temp -> next = NULL;
    if (front == NULL)
    {
        temp -> prev = NULL;
        front = temp;
    }
    else
    {
        rear -> next = temp;
        temp -> prev = rear;
    }
    rear = temp;
    printf ("New node added...\n");
}

int POP (int user_position, int size)
{
    if (!user_position)
    {
        front = rear = NULL;
    }

    else
    {
        if(user_position < ( (size + 1) / 2))
        {
            struct NODE *point = front;
            for (int i=0; i < user_position; ++i, point = point -> next);
            if (point == front)
            {
                front = rear = NULL;
            }
            else
            {
                (point -> next) -> prev = point -> prev;
                (point -> prev) -> next = point -> next;
            }
        }    
        else 
        {
            struct NODE *point = rear;
            for (int i = size; i > user_position; --i, point = point -> prev);
            if (point == rear)
            {
                (rear -> prev) -> next = NULL;
                rear = rear -> prev; 
            }
            else
            {
                (point -> next) -> prev = point -> prev;
                (point -> prev) -> next = point -> next;
            }        
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
    int DeleteNodePosition, size=0;
    char yn['!'];
    printf ("Firstly Input Nodes.\n");
    do
    {
        ++size;
        PUSH();
        printf ("\nEnter more nodes? y/n...\n>");
        scanf ("%s", &yn);
    } while (strcmpi (yn, "n"));
    
    printf ("Your created list is: ");
    TRAVERSE();

    printf ("Which Node do you wish to delete? Write it's position (Enter 0 if you wish to delete the entire node) :  ");
    scanf ("%d", &DeleteNodePosition);
    POP (DeleteNodePosition, size);

    printf ("Your new list is: ");
    TRAVERSE();
     
    return 0;
}