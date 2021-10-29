/*
Question: Write a Java program to implement Huffman encoding.
Instruction:  A binary code encodes each character as a binary string or codeword. We would like to find a binary code that encodes the file using as few bits as possible, ie., compresses it as much as possible.
              input = Huffman coding is a data compression algorithm.
              output = 110001101011000000000110010011110000111110110011111011100011001111101110001010011001010110110101000011111001101101010010110000101110111111111001111000101010100001111000101111110111101000110
              We will use a priority queue for building Huffman Tree, where the node with the lowest frequency has the highest priority. Following are the complete steps:
              1. Create a leaf node for each character and add them to the priority queue.
              2. While there is more than one node in the queue:
                > Remove the two nodes of the highest priority (the lowest frequency) from the queue.
                > Create a new internal node with these two nodes as children and a frequency equal to the sum of both nodes’ frequencies.
                > Add the new node to the priority queue.
               3. The remaining node is the root node and the tree is complete.
*/

//My Approach/Solution:
import java.util.*;
import java.lang.*;

class NODE
{
    Character ch;
    Integer freq;
    NODE left = null, right = null;
 
    NODE(Character ch, Integer freq) {
        this.ch = ch;
        this.freq = freq;
    }
 
    public NODE(Character ch, Integer freq, NODE left, NODE right) {
        this.ch = ch;
        this.freq = freq;
        this.left = left;
        this.right = right;
    }
}
 
public class HuffmanEncoding {
    public static void encode(NODE root, String str, Map<Character, String> HuffmanCode) {
        if (root != null) {
            if (root.left == null && root.right == null)
                HuffmanCode.put(root.ch, str.length() > 0 ? str : "1");
            encode(root.left, str + '0', HuffmanCode);
            encode(root.right, str + '1', HuffmanCode);
        }   
    }      
    public static void main(String[] args) {
        Scanner Scan = new Scanner (System.in);
        //System.out.print ("Enter the string to be encoded: ");
        String input = Scan.nextLine();

        if (input.length() > 0) { 
            Map<Character, Integer> frequency = new HashMap<>();
            for (char c: input.toCharArray()) {
                frequency.put(c, frequency.getOrDefault(c, 0) + 1);
            }

            PriorityQueue<NODE> PriorityQ;
            PriorityQ = new PriorityQueue<>(Comparator.comparingInt(l -> l.freq));

            for (var entry: frequency.entrySet())
                PriorityQ.add(new NODE(entry.getKey(), entry.getValue()));
            
            while (PriorityQ.size() != 1) {                
                NODE left = PriorityQ.poll();
                NODE right = PriorityQ.poll();
                int sum = left.freq + right.freq;
                PriorityQ.add(new NODE(null, sum, left, right));
            }
            
            NODE root = PriorityQ.peek();
            Map<Character, String> HuffmanCode = new HashMap<>();
            encode(root, "", HuffmanCode);
            
            StringBuilder output = new StringBuilder();
            for (char c: input.toCharArray()) {
                output.append(HuffmanCode.get(c));
            }

            //System.out.print ("The Encoded Huffman Code is: ");
            System.out.print(output);
        }
    }
}
