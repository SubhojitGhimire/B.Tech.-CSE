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
    /*
    for (i=0; i<row; ++i)
    {
        for(j=0; j<col; ++j)
        {
            scanf ("%d", &matA [i][j]);
            if (matA[i][j] != 0)
            {
                sparseA [0][k1] = i;
                sparseA [1][k1] = j;
                sparseA [2][k1] = matA [i][j];
                ++k1;
            }
        }
    }
    */

    printf ("\nEnter Values into your matrix B:\n");

    EnterValueInMatrix (matB, row, col, sparseB, &k2);
    /*for (i=0; i<row; ++i)
    {
        for(j=0; j<col; ++j)
        {
            scanf ("%d", &matB [i][j]);
            if (matB[i][j] != 0)
            {
                sparseB [0][k2] = i;
                sparseB [1][k2] = j;
                sparseB [2][k2] = matB [i][j];
                ++k2;
            }
        }
    }
    */

    printf ("\n### MATRIXES CREATED ### \n\n");

    printf ("Matrix A\n");

    PrintMatrix (matA, row, col);
    /*for (i=0; i<row; ++i)
    {
        for (j=0; j<col; ++j)
        {
            printf ("%d\t", matA[i][j]);
        }
        printf ("\n");
    }
    */

    printf ("\nCorresponding Sparse Matrix A\n");

    PrintSparse (sparseA, k1);
    /*for (i=0; i<3; ++i)
    {
        for (j=0; j<k1; ++j)
        {
            printf ("%d\t", sparseA[i][j]);
        }
        printf ("\n");
    }
    */

    printf ("\nMatrix B\n");

    PrintMatrix (matB, row, col);
    /*for (i=0; i<row; ++i)
    {
        for (j=0; j<col; ++j)
        {
            printf ("%d\t", matB[i][j]);
        }
        printf ("\n");
    }
    */

    printf ("\nCorresponding Sparse Matrix B\n");

    PrintSparse (sparseB, k2);
    /*for (i=0; i<3; ++i)
    {
        for (j=0; j<k2; ++j)
        {
            printf ("%d\t", sparseB[i][j]);
        }
        printf ("\n");
    }
    */    

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

