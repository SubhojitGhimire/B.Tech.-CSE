import java.util.Scanner;
import java.lang.String;

public class BreakString {
    public static void main (String[] args) {
        Scanner Scan = new Scanner(System.in);
        System.out.println ("Enter a string:");
        String input = Scan.nextLine();
        for (int i=0; i<input.length(); ++i) {
            if ((input.charAt(i)>='a' && input.charAt(i)<='z') || (input.charAt(i)>='A' && input.charAt(i)<='Z')) {
                System.out.print (input.charAt(i));
            }
            else if (i<input.length()-1) {
                if ((input.charAt(i+1)>='a' && input.charAt(i+1)<='z') || (input.charAt(i+1)>='A' && input.charAt(i+1)<='Z')) {
                    System.out.print ("\n" + input.charAt(i+1));
                    ++i;
                }
            }
        }
        Scan.close();
    }
}