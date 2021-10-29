#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE
{
    int value;
    struct NODE *next;
}*top = NULL, *bottom = NULL;

int PUSH (int position)
{
    struct NODE *newnode = (struct NODE*) malloc (sizeof (struct NODE));
    int num;
    printf ("Enter Value to be added: ");
    scanf ("%d", &num);
    newnode->value = num;
    if (!position)
    {
        if (top == NULL)
        {
            newnode->next = NULL;
            bottom = newnode;
        }
        else
        {
            newnode -> next = top;
        }
        top = newnode;
    }
    else
    {
        struct NODE *point = top;
        for (int i=0; i < position-1; ++i)
        {
            point = point -> next;
        }
        newnode -> next = point -> next;
        point -> next = newnode;
    }
    
    printf ("New node stacked...\n");
    return 0;
}

int POP (int position)
{
    struct NODE *point = top;
    for (int i=0; i < (position - 1); ++i)
    {
        point = point -> next;
    }
    point -> next = (point -> next) -> next;
    return 0;
}

int TRAVERSE ()
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
    return 0;
}

int main()
{
    int NodePosition, size=0, pos=0;
    char yn['!'];
    printf ("Firstly Input Nodes.\n");
    do
    {
        ++pos;
        PUSH(0);
        printf ("\nEnter more nodes? y/n...\n>");
        scanf ("%s", &yn);
    } while (strcmpi (yn, "n"));
    
    printf ("Your created list is: ");
    TRAVERSE();

    printf ("Adding new node at the middle location ");
    PUSH (pos/2);
    ++pos;
    TRAVERSE();

    printf ("Deleting Node from the middle position\n");
    POP (pos/2);

    printf ("Your new list is: ");
    TRAVERSE();
     
    return 0;
}