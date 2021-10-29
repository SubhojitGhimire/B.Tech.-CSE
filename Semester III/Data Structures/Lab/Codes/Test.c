#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct Stack {
    int token;
    struct Stack *prev;
} Stack;

Stack *push(Stack *top, int token) {
    Stack newNode = (Stack)malloc(sizeof(Stack*));
    newNode->token = token;
    newNode->prev = NULL;
    if(top == NULL) {
        return newNode;
    }
    
    newNode->prev = top;
    return newNode;
}

Stack *pop(Stack *top) {
    if(top == NULL) {
        printf("Underflow!\n");
        return NULL;
    }
    
    return top->prev;
}

int peek(Stack *top) {
    if(top == NULL) {
        return '\0';
    }
    return top->token;
}

int op(int a, int b, char c) {
    switch(c) {
        case '+' : 
            return b+a;
            break;
        case '-' : 
            return b-a;
            break;
        case '*' : 
            return b*a;
            break;
        case '/' : 
            return b/a;
            break;
        
    }
} 

int main() {
    char token;
    Stack *st = NULL;
    char exp[100];
    fgets(exp, 100, stdin);

    int i = 0;
    while(exp[i] != '\0') {
        token = exp[i];
        i++;
        if(token == ' ' || token == '\n') continue;
        if(!isdigit(token)) {
            int a = peek(st);
            st = pop(st);
            int b = peek(st);
            st = pop(st);
            int res = op(a, b, token);
            st = push(st, res);
            continue;
        }
        st = push(st, token-'0');
    }
    
    printf("%d", peek(st));
}