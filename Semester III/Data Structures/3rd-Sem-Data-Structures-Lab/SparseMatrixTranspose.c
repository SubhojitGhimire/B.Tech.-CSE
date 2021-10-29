/*
Question: Write a C program to transpose a sparse matrix.
Program Overview: a. The size m*n of the matrix is defined.
                  b. The user-input elements are entered in the matrix.
                  c. While the user is entering elements in the matrix, its corresponding sparse matrix is being defined parallely.
                  d. The created matrix is displayed on-screen in both its matrix form as well as in sparse form.
                  e. The sparse matrix is transposed, i.e., the matrix is transposed in its sparse form.
                  f. The transpose of the matrix is displayed on-screen in both sparse form as well as in matrix form.
*/

//My Approach/Solution:
#include <stdio.h>

int main()
{
    int mat ['!']['!'], sparse [3]['!'], transpose[3]['!'];
    int i, j, row, col, k=0;

    printf ("Enter the size of the matrix\n");
    printf ("Row: ");
    scanf ("%d", &row);
    printf ("Column: ");
    scanf ("%d", &col);

    printf ("Enter the elements in the matrix: \n");
    for (i=0; i<row; ++i)
    {
        for (j=0; j<col; ++j)
        {
            scanf ("%d", &mat[i][j]);
            if (mat[i][j] != 0)
            {
                sparse [0][k] = i;
                sparse [1][k] = j;
                sparse [2][k] = mat [i][j];
                ++k;
            }
        }
    }

    printf ("The Matrix you created\n");
    for (i=0; i<row; ++i)
    {
        for (j=0; j<col; ++j)
        {
            printf ("%d\t", mat[i][j]);
        }
        printf ("\n");
    }

    printf ("The Corresponding Sparse Matrix\n");
    for (i=0; i<3; ++i)
    {
        for (j=0; j<k; ++j)
        {
            printf ("%d\t", sparse[i][j]);
        }
        printf ("\n");
    }
        
    //Transposing the matrix

    for (i=0; i<k; ++i)
    {
        transpose [0][i] = sparse [1][i];
        transpose [1][i] = sparse [0][i];
        transpose [2][i] = sparse [2][i];
    }

    printf ("Sparse Transpose of the matrix you created is\n");
    for (i=0; i<3; ++i)
    {
        for (j=0; j<k; ++j)
        {
            printf ("%d\t", transpose [i][j]);
        }
        printf ("\n");
    }
    
    int count, flag;
    printf ("In matrix form, this transpose is\n");
    for (i=0; i<col; ++i)
    {
        for (j=0; j<row; ++j)
        {
            flag=0;
            for (count=0; count<k; ++count)
            {
                if (transpose [0][count] == i && transpose [1][count] == j)
                {
                    printf ("%d\t", transpose [2][count]);
                    flag=1;
                    break;
                }             
            }
            if (!flag)
                printf ("0\t");                
        }
        printf ("\n");
    }

    return 0;
}
