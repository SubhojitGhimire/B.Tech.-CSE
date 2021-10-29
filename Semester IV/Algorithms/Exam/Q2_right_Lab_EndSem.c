#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct pair {
    int first;
    int second;
    int size, store_size;
    int *next;
};

struct pair *crt(int s) {
    struct pair *q = (struct pair*) malloc(sizeof(struct pair));
    q->size = q->first = q->second = 0;
    q->store_size = s;
    q->next = (int*) malloc(s*sizeof(int));
    return q;
}

bool isSafe (int m, int n) {
    return ((m>=0) && (m<10) && (n>=0) && (n<10));
}

bool empty (struct pair **q) {
    return ((*q)->size == 0);
}

void push (struct pair **q, int num) {
    (*q) -> next[(*q) -> second] = num;
    ++((*q)->second);
    ++((*q)->size);
}

int pop (struct pair **q) {
    if (!empty(q)) {
        int num = (*q)->next[(*q)->first];
        ++((*q)->first);
        --((*q)->size);
        return num;
    }
    return -1;
}

int main () {
    int island = 0;
    int mat[10][10];
    int uncovered[10][10];
    printf ("Enter values in matrix such that 0 represents water and 1 represents land\n");
    for (int i=0; i<10; ++i)
        for (int j=0; j<10; ++j) {
            scanf ("%d", &mat[i][j]);
            uncovered[i][j] = 0;
        }

    for (int i=0; i<10; ++i)
	{
		for (int j=0; j<10; ++j)
		{
			if (mat[i][j] && !uncovered[i][j])
			{
				uncovered[i][j] = 1;
				struct pair *q1 = crt(1005);
				struct pair *q2 = crt(1005);
				push(&q1, i);
				push(&q2, j);
				while (!empty(&q1))
				{
					int num1 = pop(&q1);
					int num2 = pop(&q2);
					for (int m=num1-1; m<=num1+1; ++m)
					{
						for (int n=num2-1; n<=num2+1; ++n)
						{
							if (isSafe(m, n))
							{
								if (mat[m][n]!=0 && !uncovered[m][n])
								{
									uncovered[m][n] = 1;
									push(&q1, m);
									push(&q2, n);
								}
							}
						}
					}
				}
				free(q1);
				free(q2);
				++island;
			}
		}
	}
	printf("%d", island);
	return 0;
}