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

int insert (int option, int position)
{
    struct NODE *newnode = (struct NODE*) malloc (sizeof (struct NODE));
    int num, i;
    printf ("Enter Value to be Added: ");
        scanf ("%d", &num);
    newnode -> value = num;

    struct NODE *point = front;
    for (i=1; i<position; ++i)
    {
        point = point -> next;
    }
    if (option == 1)
    {
        newnode->next = front;
        front -> prev = newnode;
        front = newnode;
    }
    else if (option == 2)
    {
        (point -> prev) -> next = newnode;
        newnode -> prev = point -> prev;
        point -> prev = newnode;
        newnode -> next = point;
    }
    else if (option == 3)
    {
        newnode -> next = point -> next;
        newnode -> prev = point;
        (point -> next) -> prev = newnode;
        point -> next = newnode;
    }
    else if (option == 4)
    {
        newnode -> next = NULL;
        newnode -> prev = rear;
        rear -> next = newnode;
        rear = newnode;
    }
    else
    {
        printf ("Exiting...");
    }
    
    return 0;
}

int TRAVERSE ()
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
    return 0;
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
int option;
do
{
    printf ("\nYour created Nodes: ");
    TRAVERSE ();
    printf ("\nSelect the option: ");
    printf ("\n1. Add New Node at Front");
    printf ("\n2. Add New Node Before an existing Node");
    printf ("\n3. Add New Node After an existing Node");
    printf ("\n4. Add Node at Last");
    printf ("\n5. Exit\n\n> ");
    scanf ("%d", &option);
    printf ("\n");
    int position = 1;
    if (option == 2 || option == 3)
    {
        printf ("Enter position for the existing in-respect node: ");
        scanf ("%d", &position);
    }
    insert (option, position);
} while (option < 5 && option > 0);
    printf ("\nYour modified Nodes: ");
    TRAVERSE ();   

    return 0;
}