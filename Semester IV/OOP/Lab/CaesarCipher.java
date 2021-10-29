import java.util.*;
import java.lang.String;

public class CaesarCipher {
    public static void main (String [] args) {
        Scanner Scan = new Scanner (System.in);
        //System.out.println("Input your Encrypted String: ");
        String input = Scan.nextLine();
        //System.out.print("Decrypted: ");
        int adjust_places = 3;
        for (int i=0; i<input.length(); ++i) {
            if (input.charAt(i) != ' ') {
                int ascii = (int) input.charAt(i) - adjust_places;
                if (ascii < 65)
                    ascii = 91 - (65 - ascii);
                else if (ascii < 97 && ascii >= (97 - adjust_places))
                    ascii = 123 - (97 - ascii);
                char output = (char) ascii;
                System.out.print (output);
            }
            else {
                System.out.print (' ');
            }
        }
    }
}