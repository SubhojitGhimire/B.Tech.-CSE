/*
Question: Write a C Program to print a matrix in spiral order.
Instructions:   a. You are supposed to allocate the array or matrix using malloc functions.
                b. You must ensure that your solution defends any test-cases. For instance, 1x1 matrix.
                c. Input should be given by random function and the code snippet of a single dimensional array is given below- 
                #include<stdlib.h>
                #include<time.h>
                srand(time(0));
                for(i=0;i<n;i++)
                a[i]=(rand()%(upper_limit-lower_limit +1))+lower_limit;
*/

//My Approach/Solution:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int **mat, row, col, i, j, k=0, l=0;

    printf ("Enter the number of rows for your matrix: ");
    scanf ("%d", &row);
    mat=(int **) malloc (row * sizeof(int));

    printf("Enter the number of columns for your matrix: ");
    scanf ("%d", &col);
    for (i=0; i<row; ++i)
        mat [i] = (int *) malloc (col * sizeof(int));
        

    printf ("Randomly Entering values in matrix... Please Wait...");

    srand (time(0));
    for (i=0; i<row; ++i)
        for(j=0; j<col; ++j)
        {
            mat[i][j] = (rand() % (100));
        }
    printf("\nVlaues successfully stored in the matrix... This is the matrix created \n");
    for (i=0; i<row; ++i)
    {
        for (j=0 ; j<row; ++j)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    printf ("The Spiral Matrix Output is: ");

    while (k < row && l < col) 
    { 
       for (i = l; i < col; ++i) 
        { 
            printf ("%d ", mat [k][i]);
        } 
        k++; 
        for (i = k; i < row; ++i) 
        { 
            printf ("%d ", mat[i][col - 1]); 
        } 
        col--; 
        if (k < row) 
        { 
            for (i = col - 1; i >= l; --i) 
            { 
                printf ("%d ", mat[row - 1][i]);
            } 
            row--; 
        } 
  
        if (l < col) 
        { 
            for (i = row - 1; i >= k; --i) 
            { 
                printf ("%d ", mat[i][l]);
            } 
            l++; 
        } 
    } 
    return 0;
}
