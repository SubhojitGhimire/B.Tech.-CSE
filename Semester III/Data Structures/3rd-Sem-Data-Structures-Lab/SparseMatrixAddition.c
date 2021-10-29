/*
Question: Write a C program to convert two n*m matrices into sparse matrices and perform addition operation on them.
Program Overview: a. Two normal matrices of n*m size are created and user-input elements are entered.
                  b. Both the matrices are converted to corresponding sparse matrices and are displayed on-screen.
                  c. The addition operation is performed on the sparse matrices.
                  d. The added matrix in both its sparse form and its corresponding matrix form is displayed on-screen.
*/

//My Approach/Solution:
#include <stdio.h>

void EnterValueInMatrix (int mat['!']['!'], int row, int col, int sparse[3]['!'], int *k);
void PrintMatrix (int mat['!']['!'], int row, int col);
void PrintSparse (int sparse[3]['!'], int k);
void Addition (int sparseA[3]['!'], int sparseB[3]['!'], int AddMat[3]['!'], int k1, int k2, int *k3);
void PrintSparseToMatrix (int sparse[3]['!'], int k, int row, int col);

int main ()
{
    int matA['!']['!'], matB['!']['!'], sparseA[3]['!'], sparseB[3]['!'], AddMat[3]['!'];
    int row, col, k1=0, k2=0, k3=0;

    printf ("Enter the size of the matrix\n");
    printf ("Row: ");
    scanf ("%d", &row);
    printf ("Column: ");
    scanf ("%d", &col);

    printf ("\nEnter elements in matrix A\n");
    EnterValueInMatrix (matA, row, col, sparseA, &k1);

    printf ("\nEnter elements in matrix B\n");
    EnterValueInMatrix (matB, row, col, sparseB, &k2);

    printf ("Matrices Created Successfully\n");

    printf ("\nMATRIX A\n");
    PrintMatrix (matA, row, col);
    printf ("CORRESPONDING SPARSE MATRIX A\n");
    PrintSparse (sparseA, k1);
    
    printf ("\nMATRIX B\n");
    PrintMatrix (matB, row, col);
    printf ("CORRESPONDING SPARSE MATRIX B\n");
    PrintSparse (sparseB, k2);

    printf ("\n\nPerforming Addition Operation on these two created matrices...\n");
    Addition (sparseA, sparseB, AddMat, k1, k2, &k3);
    
    printf ("\nThe Sparse Matrix of the two added matrices is\n");
    PrintSparse (AddMat, k3);

    printf ("\nIn Matrix Form, this added matrix is\n");
    PrintSparseToMatrix (AddMat, k3, row, col);
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


void PrintSparse (int sparse[3]['!'], int k)
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

void Addition (int sparseA[3]['!'], int sparseB[3]['!'], int AddMat[3]['!'], int k1, int k2, int *k3)
{
    int i, j;

    for (i=0, j=0; i<k1 && j<k2; )
    {
        if ((sparseA[0][i] == sparseB[0][j]) && (sparseA[1][i] == sparseB[1][j]))
        {
            AddMat[0][*k3] = sparseA[0][i];
            AddMat[1][*k3] = sparseA[1][i];
            AddMat[2][*k3] = sparseA[2][i] + sparseB[2][j];
            ++(*k3); ++i; ++j;
        }
        else
        {
            if (sparseA[0][i] < sparseB[0][j])
            {
                AddMat[0][*k3] = sparseA[0][i];
                AddMat[1][*k3] = sparseA[1][i];
                AddMat[2][*k3] = sparseA[2][i];
                ++(*k3); ++i;
            }
            else
            {
                if ((sparseA[0][i] == sparseB[0][j]) && (sparseA[1][i] < sparseB[1][j]))
                {
                    AddMat[0][*k3] = sparseA[0][i];
                    AddMat[1][*k3] = sparseA[1][i];
                    AddMat[2][*k3] = sparseA[2][i];
                    ++(*k3); ++i;
                }
                else
                {
                    AddMat[0][*k3] = sparseB[0][j];
                    AddMat[1][*k3] = sparseB[1][j];
                    AddMat[2][*k3] = sparseB[2][j];
                    ++(*k3); ++j;
                }
                
            }
            
        }
    }

    while (i < k1)
    {
        AddMat[0][*k3] = sparseA[0][i];
        AddMat[1][*k3] = sparseA[1][i];
        AddMat[2][*k3] = sparseA[2][i];
        ++(*k3); ++i;
    }

    while (j < k2)
    {
        AddMat[0][*k3] = sparseB[0][j];
        AddMat[1][*k3] = sparseB[1][j];
        AddMat[2][*k3] = sparseB[2][j];
        ++(*k3); ++j;
    }

}

void PrintSparseToMatrix (int sparse[3]['!'], int k, int row, int col)
{
    int count=0;
    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<col; ++j)
        {
            if (sparse[0][count] == i && sparse[1][count] == j)
            {
                printf ("%d\t", sparse[2][count]);
                ++count;
            }
            else
            {
                printf ("0\t");
            }            
        }
        printf ("\n");
    }
}
