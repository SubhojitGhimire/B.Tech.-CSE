#include <stdio.h>

void print(int mat[3][100], int count)
{
    int i, j;
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < count; i++)
        {
            printf("%d\t", mat[j][i]);
        }
        printf("\n");
    }    
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int mat[3][100], int count)
{
    int i, j;
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {

            if (mat[0][j] > mat[0][j + 1])
            {

                swap(&mat[0][j], &mat[0][j + 1]);
                swap(&mat[1][j], &mat[1][j + 1]);
                swap(&mat[2][j], &mat[2][j + 1]);
            }
            else if (mat[0][j] == mat[0][j + 1])
            {
                if (mat[1][j] > mat[1][j + 1])
                {
                    swap(&mat[0][j], &mat[0][j + 1]);
                    swap(&mat[1][j], &mat[1][j + 1]);
                    swap(&mat[2][j], &mat[2][j + 1]);
                }
            }
        }
    }
}

void transpose(int mat[3][100], int count)
{
    int i, j, temp;
    printf("\n");

    for (j = 0; j < count; j++)
    {

        swap(&mat[0][j], &mat[1][j]);
    }
    sort(mat, count);
}

void multiply(int matA[3][100], int count1, int r1, int c1, int matB[3][100], int count2, int r2, int c2)
{
    int i, j;
    int pos1, pos2, result[3][100], r, c, temp1, temp2, sum, rcount = 0;
    
    if (c1 != r2)
    {
        printf("not valid");
        return;
    }

    transpose(matB, count2);

    for (pos1 = 0; pos1 < count1;)
    {
        r = matA[0][pos1];
        for (pos2 = 0; pos2 < count2;)
        {
            c = matB[0][pos2];

            temp1 = pos1;
            temp2 = pos2;

            sum = 0;

            while (temp1 < count1 && matA[0][temp1] == r && temp2 < count2 && matB[0][temp2] == c)
            {
                if (matA[1][temp1] < matB[1][temp2])
                {
                    temp1++;
                }
                else if (matB[1][temp2] > matA[1][temp1])
                {
                    temp2++;
                }
                else
                {
                    sum += matA[2][temp1++] * matB[2][temp2++];
                }
            }

            if (sum != 0)
            {
                result[0][rcount] = r;
                result[1][rcount] = c;
                result[2][rcount] = sum;
                rcount++;
            }
            while (pos2 < count2 && matB[0][pos2] == c)
            {
                pos2++;
            }
        }
        while (pos1 < count1 && matA[0][pos1] == r)
        {
            pos1++;
        }
    }

    print(result, rcount);
}

int main()
{
    int MatA[20][20], SparseA[3][100], m1, n1, count1 = 0;
    int MatB[20][20], SparseB[3][100], m2, n2, count2 = 0;
    int i, j;
	printf ("Enter size of the Matrix A\n");
    printf("row: ");
    scanf("%d", &m1);
    printf("col: ");
    scanf("%d", &n1);

	printf ("Enter values in Matrix A: ");
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            scanf("%d", &MatA[i][j]);
            if (MatA[i][j])
            {
                SparseA[0][count1] = i;
                SparseA[1][count1] = j;
                SparseA[2][count1] = MatA[i][j];
                count1++;
            }
        }
    }

    printf("\nEnter size of the Matrix B\n");
	printf ("row: ");
    scanf("%d", &m2);
    printf ("col: ");
    scanf("%d", &n2);

    printf ("Enter values in Matrix B: ");
    for (i = 0; i < m2; i++)
    {
        for (j = 0; j < n2; j++)
        {
            scanf("%d", &MatB[i][j]);
            if (MatB[i][j] != 0)
            {
                SparseB[0][count2] = i;
                SparseB[1][count2] = j;
                SparseB[2][count2] = MatB[i][j];
                count2++;
            }
        }
    }

    multiply(SparseA, count1, m1, n1, SparseB, count2, m2, n2);
}