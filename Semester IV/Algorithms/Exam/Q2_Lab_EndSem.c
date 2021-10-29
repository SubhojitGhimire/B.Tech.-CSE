#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct pair {
    int first;
    int second;
    struct pair *next;
} *front=NULL, *rear=NULL;

void PUSH (int m, int n)
{
    struct pair *temp = (struct pair*) malloc (sizeof (struct pair));
    temp->first = m;
    temp->second = n;
    temp->next=NULL;
    if (front == NULL)
    {
        front = temp;
    }
    else
    {
        rear -> next = temp;
    }
    rear = temp;
}

void POP ()
{
    if (front == NULL)
    {
        return;
    }
    else if (front -> next == NULL)
    {
        rear -> next = NULL;
        rear = front = NULL;
    }   
    else
    {
        front = front -> next;
    }
}

bool isSafe (int mat[10][10], int m, int n, bool uncovered[10][10]) {
    return ((m>=0) && (m<10) && (n>=0) && (n<10) && (mat[m][n] && !uncovered[m][n]));
}

void BFS (int mat[10][10], int m, int n, bool uncovered[10][10]) {
    int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    //queue<pair<int, int>> q;
    struct pair *q = front;
    //q.push(make_pair (m, n));
    PUSH (m, n);
    uncovered[m][n] = true;

    //while (!q.empty()) {
    while (q != NULL) {
        //int i = q.front().first;
        int i = q->first;
        //int j = q.front().second;
        int j = q->second;
        //q.pop();
        POP ();

        for (int k=0; k<8; ++k) {
            if (isSafe(mat, i+row[k], j+col[k], uncovered)) {
                uncovered[i+row[k]][j+col[k]] = true;
                //q.push (make_pair(i+row[k], j+col[k]));
                PUSH (i+row[k], j+col[k]);
            }
        }
        q = q->next;
    }
} 

int main () {
    printf ("Start\n");
    /*
    int mat[10][10];
    printf ("Enter values in matrix such that 0 represents water and 1 represents land\n");
    for (int i=0; i<10; ++i)
        for (int j=0; j<10; ++j)
            scanf ("%d", &mat[i][j]);

   
   int mat[10][10] = 
   {
        { 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
        { 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
        { 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
        { 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
        { 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
   };
    */

   int mat[10][10] = 
   {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
   };
    bool uncovered[10][10];
    memset (uncovered, 0, sizeof(uncovered));

    int island = 0;
    for (int i=0; i<10; ++i) {
        for (int j=0; j<10; ++j) {
            if (mat[i][j] && !uncovered[i][j]) {
                BFS (mat, i, j, uncovered);
                ++island;
            }
        }
    }

    printf ("Islands = ");
    printf ("%d",island);
    
    return 0;
}