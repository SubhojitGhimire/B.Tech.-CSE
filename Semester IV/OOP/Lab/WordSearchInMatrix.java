import java.util.*;
import java.lang.*;

public class WordSearchInMatrix {
    public static void wordFinder (String Fruit, int i, int j, char[][] mat, int size) {
        int FruitLength = Fruit.length();
        int k, l;
        for (k=i, l=0; l<FruitLength && k<size; ++k, ++l) {
            if (Fruit.charAt(l) != mat[k][j]) {
                break;
            }
        }
        if (l == FruitLength) {
            System.out.print(i+" "+j+" ");
            return;
        }

        for (k=i, l=0; l<FruitLength && k>=0; --k, ++l) {
            if (Fruit.charAt(l) != mat[k][j]) {
                break;
            }
        }
        if (l == FruitLength) {
            System.out.print(i+" "+j+" ");
            return;
        }

        for (k=j, l=0; l<FruitLength && k<size; ++k, ++l) {
            if (Fruit.charAt(l) != mat[i][k]) {
                break;
            }
        }
        if (l == FruitLength) {
            System.out.print(i+" "+j+" ");
            return;
        }

        for (k=j, l=0; l<FruitLength && k>=0; --k, ++l) {
            if (Fruit.charAt(l) != mat[i][k]) {
                break;
            }
        }
        if (l == FruitLength) {
            System.out.print(i+" "+j+" ");
            return;
        }
    }
    public static void main (String[] args) {
        Scanner Scan = new Scanner (System.in);
        //System.out.print ("Enter size of the square matrix: ");
        int size = Scan.nextInt();
        char[][] mat = new char[size][size];
        Scan.nextLine();
        //System.out.println ("Input character elements into your matrix: ");
        for (int i=0; i<size; ++i)
            for (int j=0; j<size; ++j)
                mat[i][j] = Scan.next().charAt(0);
        //char[][] mat = {{'V', 'N', 'Y', 'B', 'K', 'G', 'S'}, {'R', 'O', 'R', 'A', 'N', 'G', 'E'}, {'E', 'T', 'R', 'N', 'X', 'W', 'P'}, {'L', 'A', 'E', 'A', 'L', 'K', 'A'}, {'P', 'M', 'H', 'N', 'W', 'M', 'R'}, {'P', 'O', 'C', 'A', 'X', 'B', 'G'}, {'A', 'T', 'N', 'O', 'M', 'E', 'L'}};
        String[] Fruits = {"APPLE", "BANANA", "CHERRY", "GRAPES", "LEMON", "ORANGE", "TOMATO"};
        int i, j, k;
        //System.out.print ("Output: ")
        for (k=0; k<7; ++k) {
            for (i=0; i<size; ++i) {
                for (j=0; j<size; ++j) {
                    if (mat[i][j] == Fruits[k].charAt(0))
                        wordFinder (Fruits[k], i, j, mat, size);
                }                    
            }
        }
    }
}