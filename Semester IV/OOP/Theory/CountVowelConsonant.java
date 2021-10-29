import java.util.*;
import java.lang.*;

class CountVowelConsonant {
    public static int countVowel (int vowel, String input) {
        for (int i=0; i<input.length(); ++i) {
            if (input.charAt(i) == 'A' || input.charAt(i) == 'E' || input.charAt(i) == 'I' || input.charAt(i) == 'O' || input.charAt(i) == 'U')
                ++vowel;
        }
        return (vowel);
    }
    public static int countCons (int cons, String input) {
        for (int i=0; i<input.length(); ++i) {
            if (!(input.charAt(i) == 'A' || input.charAt(i) == 'E' || input.charAt(i) == 'I' || input.charAt(i) == 'O' || input.charAt(i) == 'U'))
                if (input.charAt(i) > 'A' && input.charAt(i) < 'Z')
                ++cons;
        }
        return (cons);
    }
    public static void main (String[] args) {
        Scanner Scan = new Scanner (System.in);
        System.out.print ("Enter String: ");
        String input = Scan.nextLine ();
        input = input.toUpperCase();
        int vowel = 0, cons = 0;
        System.out.println ("Number of Vowels in the string = " + countVowel (vowel, input));
        System.out.println ("Number of Consonants in the string = " + countCons (cons, input));
    }
}