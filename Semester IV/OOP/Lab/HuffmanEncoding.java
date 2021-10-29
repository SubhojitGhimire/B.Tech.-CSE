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