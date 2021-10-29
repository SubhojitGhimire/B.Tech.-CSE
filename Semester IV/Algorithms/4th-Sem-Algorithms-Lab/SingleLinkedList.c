/*
Question: Write a C program to implement Single Linked List.
Instructions: Implement Single Linked List with following operations
                1. Insert at End
                2. Display
                3. Reverse (without change the node values)
                4. Sort
                5. Exit
              Each time user has to give the choice of operations. upon selection of choice 5, program will terminate.
              Input/output
              Enter your choice: 2
              List is Empty
              Enter your choice: 1
              Enter Data to Insert: 10
              Enter your choice: 1
              Enter Data to Insert: 20
              Enter your choice: 1
              Enter Data to Insert: 5
              Enter your choice: 1
              Enter Data to Insert: 3
              Enter your choice: 2
              List of Elements: 10 20 5 3
              Enter your choice: 3
              Reverse List of Elements: 3 5 20 10
              Enter your choice: 2
              List of Elements: 10 20 5 3
              Enter your choice: 1
              Enter Data to Insert: 12
              Enter your choice: 2
              List of Elements: 10 20 5 3 12
              Enter your choice: 4
              Sorted List of Elements: 3 5 10 12 20
              Enter your choice: 2
              List of Elements: 3 5 10 12 20
              Enter your choice: 5
*/

//My Approach/Solution:
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
        while (temp) {
            printf ("%d ", temp -> value);
            temp = temp -> next;
        }
        printf ("\n");
    }
}

void REVERSE () {
    struct NODE *temp = start;
    int temparr ['!'], i=0;
    while (temp) {
        temparr [i++] = temp -> value;
        temp = temp -> next;
    }
    --i;
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
        for (j=start; j!=end; j=j->next) {          //Not exactly the implementation of bubble sort due to some error when j!=i->next; is done
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

/*
void SORT () {
    int flag, TempData; 
    struct NODE *temp; 
    struct NODE *ptr = NULL; 
    do { 
        flag = 0; 
        temp = start; 
        while (temp->next != ptr) { 
            if (temp->value > temp->next->value) {   
                TempData = temp->value;
                temp->value = temp->next->value;
                temp->next->value = TempData;
                ++flag; 
            } 
            temp = temp->next; 
        } 
        ptr = temp; 
    } while (flag); 
    printf ("Sorted List of Elements: ");
    temp = start;
    while (temp) {
        printf ("%d ", temp -> value);
        temp = temp -> next;
    }
    printf ("\n");
}
*/

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
