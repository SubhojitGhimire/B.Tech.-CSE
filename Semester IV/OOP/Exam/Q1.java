//Program saved as "Q1.java"

import java.util.*;

class Matrix {
    int row, col;
    int[][] output;

    public Matrix (int r_row, int c_col) {
        row = r_row;
        col = c_col;
        output = new int[row][col];
    }

    public int getRow () {
        return row;
    }

    public int getColumn () {
        return col;
    }

    public int getElements (int r_row, int c_col) {
        return output[r_row][c_col];
    }

    public void setAt (int r_row, int c_col, int element) {
        output[r_row][c_col] = element;
    }

    public static Matrix addMat (Matrix m1, Matrix m2) {
        if ((m1.row==m2.row) && (m1.col==m2.col)) {
            Matrix m = new Matrix (m1.row, m2.col);
            for (int i=0; i<m.row; ++i) {
                for (int j=0; j<m.col; ++j) {
                    m.setAt(i, j, (m1.getElements(i, j)+m2.getElements(i, j)));
                }
            }
            return m;
        }
        else {
            System.out.println ("Matrices cannot be added");
            return new Matrix(0, 0);
        }
    }

    public static Matrix product (Matrix m1, Matrix m2) {
        Matrix m = new Matrix (m1.row, m2.col);

        for (int i=0; i<m1.row; ++i) {
            for (int k=0; k<m2.col; ++k) {
                int sum = 0;
                for (int j=0; j<m1.col; ++j) {
                    sum += m1.getElements(i, j)*m2.getElements(j, k);
                }
                m.setAt(i, k, sum);
            }
        }
        return m;
    }

    public void printMatrix (char num) {
        System.out.println ("The matrix " + num + " is: ");
        for (int i=0; i<row; ++i) {
            for (int j=0; j<col; ++j) {
                System.out.print (output[i][j] + "\t");
            }
            System.out.print ("\n");
        }
    }
}

public class Q1 {
    public static void main (String[] args) {
        Matrix mat1 = new Matrix (3, 3);
        Matrix mat2 = new Matrix (3, 3);
        int value=1;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                mat1.setAt (i, j, value);
                ++value;
                mat2.setAt (i, j, value);
                ++value;
            }
        }

        mat1.printMatrix('1');
        mat2.printMatrix('2');

        Matrix sum = Matrix.addMat(mat1, mat2);
        sum.printMatrix('+');

        Matrix pro = Matrix.product(mat1, mat2);
        pro.printMatrix('*');
    }
}














































/*
import java.util.*;

class Matrix {
    private int row;
    private int col;
    private double[][] mat;

    matrix () {
        row = 0;
        col = 0;
        mat = new double [row][col];
    }

    matrix (int rNo, int cNo) {
        row = rNo;
        col = cNo;
        mat = new double [row][col];
    }

    public void getElements () {
        Scanner Scan = new Scanner (System.in);
        int i=0, j=0;

        System.out.println ("Enter elements in the matrix:");
        for (i=0; i<row; ++i)
            for (j=0; j<col; ++j)
                mat[i][j] = Scan.nextDouble();
    }

    public void setAt (int rNo, int cNo) {
        Scanner Scan = new Scanner (System.in);
        if (rNo<=this.row && cNo<=this.col) {
            System.out.print ("Enter element to be set at mentioned position: ");
            mat[rNo-1][cNo-1] = Scan.nextDouble();
        }
    }

    public matrix addMat (matrix mat2) {
        matrix sum = new matrix (row, col);
        
        if (this.row != mat2.row || this.col != mat2.col) {
            System.out.println ("Matrices cannot be added");
        }
        else {
            for (int i=0; i<row; ++i) {
                for (int j=0; j<col; ++j) {
                    sum.mat[i][j] = this.mat[i][j] + mat2.mat[i][j];
                }
            }
        }
        return sum;
    }

    public matrix multMat (matrix mat2) {
        matrix pro = new matrix (row, col);

        if (!(this.col == mat2.row)) {
            System.out.println ("Matrices cannot be multiplied");
        }
        else {
            int i, j, k;
            for (i=0; i<this.row; ++i) {
                for (k=0; k<mat2.col; ++j) {
                    pro[i][k] = 0;
                    for ( j=0; j<this.col;++k) {
                        pro[i][k] += mat[i][j]*mat2[j][k];
                    }
                }
            }
        }
        return pro;
    }
}

public class Q1 {
    public static void main(String[] args) {
        Scanner Scan = new Scanner (System.in);
        

        System.out.println ("Enter ")
    }
}
*/