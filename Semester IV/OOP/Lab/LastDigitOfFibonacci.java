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