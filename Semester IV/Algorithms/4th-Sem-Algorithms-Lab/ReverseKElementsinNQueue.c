/*
Question: Write a program to reverse the first K elements in a queue of N elements using array.
Instructions: Reverse first K elements out of N elements 
              1. The first line of input will be N.
              For example: N = 4
              2. The second line of input will be space-separated N elements.
              For example: 7 8 5 9
              3. The third line of input will be the value of K.
              For example : K = 2
              Output : 8 7 5 9
*/              

//My Approach/Solution:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QUEUE {
    int value;
    struct QUEUE *next;
} *begin[2], *end[2];

int PUSH (int number, int index) {
    struct QUEUE *storeElements = (struct QUEUE*) malloc (sizeof (struct QUEUE));
    storeElements -> value = number;
    storeElements -> next = NULL;
    if (begin[index] == NULL) {
        begin[index] = storeElements;
    }
    else {
        end[index] -> next = storeElements;
    }
    end[index] = storeElements;
    return 0;
}

int TRAVERSE (int index)
{
    if (begin[index] == NULL)
        printf ("Queue Empty...\n");
    else
    {
        struct QUEUE *temp = begin[index];
        //printf ("Values are: ");
        while (temp)
        {
            printf ("%d ",temp -> value);
            temp = temp->next;
        }
        //printf ("\n");
    }
    return 0;
}

int main () {
    int N;
    //printf ("Enter size of elements: ");
    scanf ("%d", &N);

    char elements['!'];
    //printf ("Enter elements separated by space\n> ");
    scanf (" %[^\n]", &elements);

    begin[0] = end[0] = NULL;
    int j = 0;
    int number = 0;
    for (int i=0; i<N; ++i) {
        number = 0;
        for (j; j<strlen(elements); ++j) {
            if (elements[j] >= '0' && elements[j] <= '9') {
                number = number*10 + (elements[j] - '0'); 
                if (!(elements[j+1] >= '0' && elements[j] <= '9')) {
                    PUSH (number, 0);
                    ++j;
                    break;
                }
            }
        }
    }

    int K;
    //printf ("Enter how many elements to reverse: ");
    scanf ("%d", &K);

    struct QUEUE *temp = begin[0];
    for (int i=0; i<N; ++i) {
        j = K - 1 - i;
        if (i < K) {
            temp = begin[0];
            for (j; j>0; --j) {
                temp = temp->next;
            }
        }
        else if (i == K) {
            for (j=0; j<K; ++j) {
                temp = temp->next;
            }
        }
        else {
            temp = temp->next;
        }
        PUSH (temp->value, 1);
    }

    TRAVERSE (1);    

    return 0;
}
