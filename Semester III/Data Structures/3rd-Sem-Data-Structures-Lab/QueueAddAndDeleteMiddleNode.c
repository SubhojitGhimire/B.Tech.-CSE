/*
Question: Write a program in C to insert and delete a middle element of a queue.
*/

//My Approach/Solution:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QUEUE
{
    int data;
    struct QUEUE *next;
} *begin = NULL, *end = NULL;

int PUSH (int flag)
{
    struct QUEUE *NewQueue = (struct QUEUE*) malloc (sizeof (struct QUEUE));
    printf ("\nEnter Value: ");
    scanf ("%d", &(NewQueue -> data));
    if (flag == 0)
    {
        if (begin == NULL)
        {
            begin = NewQueue;
        }
        else
        {
            end -> next = NewQueue;
        }
        end = NewQueue;
        end -> next = NULL;
    }
    else
    {
        struct QUEUE *point = begin;
        for (int i=1; i<flag; ++i)
        {
            point = point -> next;
        }
        NewQueue -> next = point -> next;
        point -> next = NewQueue;
    }
    return 0;
}

int POP (int flag)
{
    if (begin == NULL)
    {
        printf ("\nQUEUE UNDERFLOW\n");
    }
    else
    {
        struct QUEUE *point = begin;
        for (int i=1; i<flag; ++i)
        {
            point = point -> next;
        }
        point -> next = (point -> next) -> next;
    }
    return 0;
}

int TRAVERSE ()
{
    if (begin == NULL)
    {
        printf ("\nQueue Empty\n");
    }
    else
    {
        printf ("\nQueue: ");
        struct QUEUE *point = begin;
        while (point != end)
        {
            printf ("%d ", point -> data);
            point = point -> next;
        }
        printf ("%d\n", point -> data);
    }
    return 0;
}

int main()
{
    char ch['!'];
    int count = 0;
    printf ("Firstly, Enter values into the Queue\n");
    do
    {
        ++count;
        PUSH (0);
        printf ("\nEnter more? Y/N...\n> ");
        scanf ("%s", &ch);
    } while (strcmpi (ch, "n"));
    TRAVERSE ();
    printf ("\nQueue Successfully Created...\nFinding middle of the Queue to add value...\n");
    PUSH (count/2);
    TRAVERSE ();
    printf ("\nFinding middle of the Queue to delete the value...\n");
    ++count;
    POP (count/2);
    printf ("\nAll operations successfully performed. Displaying the final Queue...\n");
    TRAVERSE ();
    return 0;
}
