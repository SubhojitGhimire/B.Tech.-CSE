/*
Question: Write a program in C to implement stack using queue.
*/

//My Approach/Solution:
#include<stdio.h>
#include<stdlib.h>

#define Max 1e5

struct stack
{
	int front, rear, q1['!'], q2['!'];
}Stack;

void push (int num)
{
	if(Stack.rear == Max-1)
	{
		printf("\nSTACK OVERFLOW\n");
		return;
	}
	if(Stack.front == -1)
		Stack.front = 0;
	Stack.q1 [++(Stack.rear)] = num;
}

void pop()
{
	if(Stack.front == -1)
	{
		printf("\nSTACK UNDERFLOW\n");
		return;
	}

	else if (Stack.front == Stack.rear)
	{
		Stack.front=Stack.rear = -1;
		return;
	}

	int i = -1;
	while(Stack.front < Stack.rear)
	{
		Stack.q2 [++i] = Stack.q1 [Stack.front++];
	}
	Stack.front = 0;
	Stack.rear = -1;
	for(int j = 0; j <= i; ++j)
	{
		Stack.q1 [++(Stack.rear)] = Stack.q2 [j];
	}
}

void display()
{
	if (Stack.front == -1)
	{
		printf("\nSTACK UNDERFLOW\n");
		return;
	}
	for(int i = Stack.rear; i >= Stack.front; --i)
		printf("%d ",Stack.q1 [i]);

}

void top()
{
	if(Stack.front == -1)
	{
		printf("\nSTACK UNDERFLOW\n");
		return;
	}

	printf("\n%d\n", Stack.q1 [Stack.rear]);
	
}

int main()
{
	Stack.front=Stack.rear=-1;
	int data, option;
	do
	{
		printf ("\nMENU\n");
		printf ("1. Enter into Stack\n");
		printf ("2. Delete from Stack\n");
		printf ("3. Top of the Stack\n");
		printf ("4. Exit\n> ");
		scanf("%d",&option);
		switch (option)
		{
			case 1:	printf ("\nEnter Value: ");
					scanf("%d",&data);
					push (data);
					printf ("Added...\n");
					break;
			case 2:	pop ();
					printf ("Deleted...\n");
					break;
			case 3:	top ();
					break;
			default:
					break;
		}
	}while (option < 4);
	return 0;
}
