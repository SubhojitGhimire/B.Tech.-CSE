#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int value;
    struct NODE *next;
} *start = NULL, *end = NULL;

void INSERT () {
    struct NODE *temp = (struct NODE*) malloc (sizeof (struct NODE));
    int num;
    printf ("Enter Data to Insert: ");
    scanf ("%d", &num);
    temp -> value = num;
    temp -> next = NULL;
    if (start == NULL) {
        start = temp;
    }
    else {
        end -> next = temp;
    }
    end = temp;
}

void DISPLAY () {
    struct NODE *temp = start;
    if (start == NULL) {
        printf ("List is Empty\n");
    }
    else {
        printf ("List of Elements: ");
        while (temp != end) {
            printf ("%d ", temp -> value);
            temp = temp -> next;
        }
        printf ("%d\n", temp -> value);
    }
}

void REVERSE () {
    struct NODE *temp = start;
    int temparr ['!'], i=0;
    while (temp != end) {
        temparr [i++] = temp -> value;
        temp = temp -> next;
    }
    temparr [i] = temp -> value;
    printf ("Reverse List of Elements: ");
    while (i >= 0) {
        printf ("%d ", temparr[i--]);
    }
    printf ("\n");
}

void SORT () {
    int temp;
    struct NODE *i;
    struct NODE *j;
    for (i=start; i!=end; i=i->next) {
        for (j=start; j!=end; j=j->next) {
            if (j->value > j->next->value) {
                temp = j->value;
                j->value = j->next->value;
                j->next->value = temp;
            }
        }
    }
    printf ("Sorted ");
    DISPLAY ();
}

int main () {
    int choice;
    do {
        /*
        printf ("************************\n");
        printf ("********* MENU *********\n");
        printf ("************************\n");
        printf ("1. Insert at End\n");
        printf ("2. Display\n");
        printf ("3. Reverse (without changing the node values)\n");
        printf ("4. Sort\n");
        printf ("5. Exit\n");
        */
        printf ("Enter your choice: ");
        scanf ("%d", &choice);
        
        switch (choice) {
            case 1: INSERT (); break;
            case 2: DISPLAY (); break;
            case 3: REVERSE (); break;
            case 4: SORT (); break;
            case 5: exit (0);
        }
    } while (choice < 5);
    return 0;
}