//LAB-1. Q.1 Write a program to rotate a matrix in 90 degree angle.

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