#include <stdio.h>

void checkIsland (int mat[10][10], int i, int j, int row, int col) {
    if (i && j) {  
        if (mat[i-1][j-1] > 1) {
            mat[i][j] = mat[i-1][j-1];
            return;
        }
    }
    if (i) {
        if (mat[i-1][j] > 1) {
            mat[i][j] = mat[i-1][j];
            return;
        }
    }
    if (i && j<col-1) {
        if (mat[i-1][j+1] > 1)  {
            mat[i][j] = mat[i-1][j+1];
            return;
        }
    }
    if (j) {
        if (mat[i][j-1] > 1) {
            mat[i][j] = mat[i][j-1];
            return;
        }
    }
    if (j<col-1) {
        if (mat[i][j+1] > 1) {
            mat[i][j] = mat[i][j+1];
            return;
        }
    }
    if (j && i<row-1) {
        if (mat[i+1][j-1] > 1) {
            mat[i][j] = mat[i+1][j-1];
            return;
        }
    }
    if (i<row-1) {
        if (mat[i+1][j] > 1) {
            mat[i][j] = mat[i+1][j];
            return;
        }
    }
    if (i<row-1 && j<col-1) {
        if (mat[i+1][j+1] > 1) {
            mat[i][j] = mat[i+1][j+1];
            return;
        }
    }
}

void markIsland (int mat[10][10], int i, int j, int row, int col) {
    if ((i && j) && (mat[i-1][j-1] > 1))
        mat[i-1][j-1] = mat[i][j];
    if (i && (mat[i-1][j] > 1))
        mat[i-1][j] = mat[i][j];
    if ((i && j<col-1) && (mat[i-1][j+1] > 1))
        mat[i-1][j+1] = mat[i][j];
    if (j && (mat[i][j-1] > 1))
        mat[i][j-1] = mat[i][j];
    if ((j<col-1) && (mat[i][j+1] > 1))
        mat[i][j+1] = mat[i][j];
    if ((j && i<row-1) && (mat[i+1][j-1] > 1))
        mat[i+1][j-1] = mat[i][j];
    if ((i<row-1) && (mat[i+1][j] > 1))
        mat[i+1][j] = mat[i][j];
    if ((i<row-1 && j<col-1) && (mat[i+1][j+1] > 1))
        mat[i+1][j+1] = mat[i][j];
}

void surfIsland (int mat[10][10], int x, int y, int row, int col, int *countIsland) {
    for (int j=col-1; j>=0; --j) {
        if (mat[x][j] == 1) {
            checkIsland (mat, x, j, row, col);
        if (mat[x][j] > 1)
            markIsland (mat, x, j, row, col);
        }
    }
    if (mat[x][y] == 1) {
        mat[x][y] = (*countIsland)++;
        markIsland (mat, x, y, row, col);
    }
}

int main () {
    int row, col;
    printf ("Enter row\n> ");
    scanf ("%d", &row);
    printf ("Enter column\n> ");
    scanf ("%d", &col);

    int countIsland = 2;
    //int mat[row][col];
    int mat[10][10] = {     {1, 0, 1, 0, 0, 0, 1, 1, 1, 1},
                            {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                            {1, 1, 1, 1, 0, 0, 1, 0, 0, 0},
                            {1, 0, 0, 1, 0, 1, 0, 0, 0, 0},
                            {1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
                            {0, 1, 0, 1, 0, 0, 1, 1, 1, 1},
                            {0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
                            {0, 0, 0, 1, 0, 0, 1, 1, 1, 0},
                            {1, 0, 1, 0, 1, 0, 0, 1, 0, 0},
                            {1, 1, 1, 1, 0, 0, 0, 1, 1, 1}};

    for (int i=0; i<row; ++i) {
        for (int j=0; j<col; ++j) {
            printf ("%d\t", mat[i][j]);
        }
        printf ("\n");
    }

    //printf ("Input 0 for water and 1 for land:\n");
    for (int i=0; i<row; ++i) {
        for (int j=0; j<col; ++j) {
            //scanf ("%d", &mat[i][j]);
            if (mat[i][j])
                surfIsland (mat, i, j, row, col, &countIsland);
        }
    }

    printf ("Total Number of Islands = %d\n", countIsland-3);

    for (int i=0; i<row; ++i) {
        for (int j=0; j<col; ++j) {
            printf ("%d\t", mat[i][j]);
        }
        printf ("\n");
    }
}

/*
mat[10][10] = { {1, 0, 1, 0, 0, 0, 1, 1, 1, 1},
                {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                {1, 1, 1, 1, 0, 0, 1, 0, 0, 0},
                {1, 0, 0, 1, 0, 1, 0, 0, 0, 0},
                {1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
                {0, 1, 0, 1, 0, 0, 1, 1, 1, 1},
                {0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
                {0, 0, 0, 1, 0, 0, 1, 1, 1, 0},
                {1, 0, 1, 0, 1, 0, 0, 1, 0, 0},
                {1, 1, 1, 1, 0, 0, 0, 1, 1, 1}};
*/