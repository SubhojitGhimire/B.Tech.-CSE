/*
Question: Write a C program to convert a user created m*n matrix to its corresponding sparse matrix.
Program Overview: a. The size m*n of the matrix is defined.
                  b. The user is asked to enter values in matrices (two matrices A and B are created).
                  c. As the user is entering values in a matrix, its sparse matrix is being defined parallely.
                  d. Both the normal matrices along with their sparse matrices are displayed on-screen, simultaneously.
*/

//My Approach/Solution:
#include <stdio.h>

void EnterValueInMatrix (int mat['!']['!'], int row, int col, int sparse[3]['!'], int *k);
void PrintMatrix (int mat['!']['!'], int row, int col);
void PrintSparse (int sparse[3]['!'], int k);

int main ()
{
    int matA['!']['!'],matB['!']['!'], sparseA[3]['!'], sparseB[3]['!'];
    int i, j, row, col, m, n, k1=0, k2=0;

    printf ("Enter the size of the matrix: \n");
    printf ("Row: ");
    scanf ("%d", &row);
    printf ("Column: ");
    scanf ("%d", &col);

    printf ("\nEnter Values into your matrix A:\n");
    EnterValueInMatrix (matA, row, col, sparseA, &k1);
    printf ("\nEnter Values into your matrix B:\n");
    EnterValueInMatrix (matB, row, col, sparseB, &k2);
    printf ("\n### MATRIXES CREATED ### \n\n");

    printf ("Matrix A\n");
    PrintMatrix (matA, row, col);
    printf ("\nCorresponding Sparse Matrix A\n");
    PrintSparse (sparseA, k1);

    printf ("\nMatrix B\n");
    PrintMatrix (matB, row, col);
    printf ("\nCorresponding Sparse Matrix B\n");
    PrintSparse (sparseB, k2);

    return 0;
}



void EnterValueInMatrix (int mat['!']['!'], int row, int col, int sparse['!']['!'], int *k)
{
    for (int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
        {
            scanf ("%d", &mat [i][j]);
            if (mat[i][j] != 0)
            {
                sparse [0][*k] = i;
                sparse [1][*k] = j;
                sparse [2][*k] = mat [i][j];
                ++(*k);
            }
        }
    }
}


void PrintMatrix (int mat['!']['!'], int row, int col)
{
    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<col; ++j)
        {
            printf ("%d\t", mat[i][j]);
        }
        printf ("\n");
    }
}


void PrintSparse (int sparse['!']['!'], int k)
{
    for (int i=0; i<3; ++i)
    {
        for (int j=0; j<k; ++j)
        {
            printf ("%d\t", sparse[i][j]);
        }
        printf ("\n");
    }
}
