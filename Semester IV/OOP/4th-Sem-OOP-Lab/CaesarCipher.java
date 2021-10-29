/*
Question: Write a java program to decrypt an encrypted string using Caesar Cipher.
Instructions: Caesar Cipher
              The Caesar cipher is a basic encryption technique used by Julius Caesar to securely communicate with his generals. Each letter is replaced by another letter N positions down the english alphabet. For example, for a rotation of 5, the letter 'c' would be replaced by an 'h'. In case of a 'z', the alphabet rotates and it is transformed into a 'd'.
              Implement a decoder for the Caesar cipher where N = 3
              For Example
              For N=3
              HELLO is encrypted as KHOOR.
              input
              KHOOR
              output
              HELLO
*/

//My Solution/Approach:
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
