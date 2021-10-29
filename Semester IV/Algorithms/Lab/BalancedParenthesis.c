#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct STACK {
    char data;
    struct STACK *next;
} *top = NULL, *bottom = NULL;

void PUSH () {
    struct STACK *temp = (struct STACK*) malloc (sizeof (struct STACK));
    temp->data = '(';
    if (top == NULL) {
        temp->next = NULL;
        bottom = temp;
    }
    else {
        temp -> next = top;
    }
    top = temp;
}

void POP () {
    if (top == NULL) {
        return;
        //printf ("\nSTACK UNDERFLOW\n");
    }
    else if (top->data == '(') {
        if (top -> next == NULL) {
            top -> next = NULL;
            top = bottom = NULL;
        }   
        else {
            top = top -> next;
        }
    }
}

int main () {
    char input ['!'];
    //printf ("Enter expression\n> ");
    scanf (" %[^\n]", input);
    
    for (int i=0; i<strlen(input); ++i) {
        if (input[i] == '(') {
            PUSH ();
        }
        else if (input[i] == ')') {
            POP ();
        }
    }

    if (top == NULL) {
        printf ("Balanced");
    }
    else {
        printf ("Unbalanced");
    }
    return 0;
}