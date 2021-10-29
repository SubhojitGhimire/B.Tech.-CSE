/*
Question: Write a C Program to rotate a matrix in 90 degree angle.
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
    int **mat, **mat1, row, col, i, j, k;

    printf ("Enter the number of rows for your matrix: ");
    scanf ("%d", &row);
    mat=(int **) malloc (row * sizeof(int));

    printf("Enter the number of columns for your matrix: ");
    scanf ("%d", &col);
    for (i=0; i<row; ++i)
    {
        mat [i] = (int *) malloc (col * sizeof(int));
    }

    //Defining second matrix with n*p size (because that's what's gonna happen ater 90-d rotation)    
    mat1=(int **) malloc (col * sizeof(int));
    for (i=0; i<col; ++i)
    {
        mat1 [i] = (int *) malloc (row * sizeof(int));
    }

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
        for (j=0 ; j<col; ++j)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    //storing the matrix 1 into matrix 2 in 90-deg rotated order
    for (i=0; i<row; ++i)
    {
        k = col-1;
        for (j=0; j < col; ++j, --k)
        {
            mat1 [k][i] = mat [i][j];
        }
    }

    printf("\nThe 90-degree rotated matrix is: \n");
    for (i=0; i<col; ++i)
    {
        for (j=0 ; j<row; ++j)
        {
            printf("%d\t", mat1[i][j]);
        }
        printf("\n");
    }

    return 0;
}
