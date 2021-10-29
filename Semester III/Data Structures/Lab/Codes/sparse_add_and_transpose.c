#include <stdio.h>
void AddMat(int matA[3][100], int matB[3][100], int k, int l);
void TranMat (int matA[3][100], int k);

int main()
{
    int a[20][20], matA[3][100], n, m, count = 0, i, j, k = 0, b[20][20], matB[3][100], l = 0, p, q;

    printf("Enter the size of the matrix: \n");
    printf ("m: ");
	scanf ("%d", &m);
    printf("n: ");
    scanf("%d", &n);

    printf ("Enter Matrix A:\n");
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
            {
                matA[0][k] = i;
                matA[1][k] = j;
                matA[2][k] = a[i][j];
                k++;
            }
        }
    }
       
    printf ("Enter Matrix B:\n");
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                scanf("%d", &b[i][j]);
                if (b[i][j] != 0)
                {
                    matB[0][l] = i;
                    matB[1][l] = j;
                    matB[2][l] = b[i][j];
                    l++;
                }
            }
        }

        printf("\nSparse matrix A is \n");
          for (i = 0; i < 3; i++)
         {
        for (j = 0; j < k; j++)
        {
            printf("%d\t", matA[i][j]);
        }
        printf("\n");
        }

        printf("\nSparse matrix B is \n");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < l; j++)
            {
                printf("%d\t", matB[i][j]);
            }
            printf("\n");
        }
        printf ("### ADDITION ###\n"); AddMat(matA, matB, k, l);
        return 0;
    
}

void AddMat(int matA[3][100], int matB[3][100], int k, int l)
{
    int i = 0, j = 0, sparse[3][100], x = 0;

    while (i < k && j < l)
    {
        if ((matA[0][i] == matB[0][j]) && (matB[1][j] == matA[1][i]))
        {
            sparse[0][x] = matA[0][i];
            sparse[1][x] = matA[1][i];
            sparse[2][x] = matB[2][j] + matA[2][i];
            x++;
            i++;
            j++;
        }
        else
        {
            if (matA[0][i] < matB[0][j])
            {
                sparse[0][x] = matA[0][i];
                sparse[1][x] = matA[1][i];
                sparse[2][x] = matA[2][i];
                x++;
                i++;
            }

            else
            {
                if ((matA[0][i] == matB[0][j]) && (matA[1][i] < matB[1][j]))
                {
                    sparse[0][x] = matA[0][i];
                    sparse[1][x] = matA[1][i];
                    sparse[2][x] = matA[2][i];
                    x++;
                    i++;
                }
                else
                {
                    sparse[0][x] = matB[0][j];
                    sparse[1][x] = matB[1][j];
                    sparse[2][x] = matB[2][j];
                    x++;
                    j++;
                }
            }
        }
    }

    while (i < k)
    {
        sparse[0][x] = matA[0][i];
        sparse[1][x] = matA[1][i];
        sparse[2][x] = matA[2][i];
        x++;
        i++;
    }
    while (j < l)
    {
        sparse[0][x] = matB[0][j];
        sparse[1][x] = matB[1][j];
        sparse[2][x] = matB[2][j];
        x++;
        j++;
    }

    printf("\nAddition of the Matrix is \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < x; j++)
        {
            printf("%d\t", sparse[i][j]);
        }
        printf("\n");
    }

    printf ("### TRANSPOSE of added matrix ###\n"); TranMat (sparse, x);
}

void TranMat (int mat[3][100], int k)
{
	int temp, i, j;
    int transpose [3][k];
    for (j = 0; j < k; j++)
        {
            transpose [0][j] = mat [1][j];
            transpose [1][j] = mat [0][j];
            transpose [2][j] = mat [2][j];
        }
     for (i = 0; i < 3; i++)
     {        
        printf ("Transpose of the matrix is\n");
        for (i=0; i<3; ++i)
        {
            for (j=0; j< k; ++j)
            {
                printf ("%d\t", transpose [i][j]);
            }
            printf ("\n");
        }
     }
}