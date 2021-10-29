/*
Question: Write a java program to find the largest repeated substring in a given string.
Instructions: Exercise 5: Find the largest repeated substring in a given string
              Note: Largest repeated non-overlapping substring 
              Example
              input: aabababcbdbab
              output: bab
              input is either small or caps
*/

//My Approach/Solution:
import java.util.*;
import java.lang.String;

public class LargestRepeatedSubstring {
  public static void main(String[] args) {
  Scanner Scan = new Scanner (System.in);
	//System.out.print ("Enter the String: ");
	String input = Scan.nextLine();
	int LengthOfInp = input.length();
	String LrgSubstring = new String();
	int LrgCount = 0;
	//for (int i=LengthOfInp-2; i>0; --i) { if overlapping substring was allowed
	for (int i=LengthOfInp/2; i>0; --i) {
		for (int j=0; j<LengthOfInp-i; ++j) {
			String SubStr = new String();
			int SubCount = 0;
			for (int k=j; k<i+j+1; ++k)
				SubStr += input.charAt(k);
			//for (int k=j+1; k<LengthOfInp-i; ++k) { if overlapping substring was allowed
			for (int k=j+1+i; k<LengthOfInp-i; ++k) {
				String TempStr = new String ();
				for (int l=k; l<i+k+1; ++l)
					TempStr += input.charAt(l);
				if (SubStr.equals(TempStr))
					++SubCount;
			}
			if (SubCount > LrgCount) {
				LrgSubstring = LrgSubstring.replaceAll(LrgSubstring, SubStr);
				LrgCount = SubCount;
			}
		}
		if (LrgCount > 0)
			break;
	}
	//System.out.print ("The Largest Repeated Substring is: ");
	System.out.println(LrgSubstring);
    }
}
