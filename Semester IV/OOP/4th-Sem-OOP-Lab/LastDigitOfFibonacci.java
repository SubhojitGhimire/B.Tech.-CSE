/*
Question: Write a java program to display the last digit a Fibonacci Sequence of a given length.
Instructions: Fibonacci Series : 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
              Example: 
              N=10
              the 10th Fibonacci number is 55. Last digit is 5
              N=100
              the 100th Fibonacci number is 354224848179261915075. Last Digit is 5
              Input
              11
              Output
              9
*/

//My Approach/Solution:
import java.util.*;
import java.math.BigInteger;

class LastDigitOfFibonacci {
    public static BigInteger fibo (int num) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = BigInteger.ONE;
        BigInteger c = BigInteger.TWO;
        for (int i=2; i<=num; ++i) {
            c = a.add (b);
            a = b;
            b = c;
        }
        return a;
    }
    
    public static void main (String [] args) {
        Scanner input = new Scanner (System.in);
        //System.out.print ("Enter the Nth place for which you wish to get the value: ");
        int num = input.nextInt ();
        System.out.print (fibo(num).mod(BigInteger.TEN));
    }
}
