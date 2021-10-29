import java.util.Scanner;

public class BubbleSort {
    public static void bubbleSort (int[] arr) {
        for (int i=0; i<arr.length - 1; ++i) {
            for (int j=0; j<arr.length - 1 - i; ++j) {
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    public static void main (String[] args) {
        Scanner Scan = new Scanner (System.in);
        System.out.print ("Enter the size fo the array: ");
        int size = Scan.nextInt();
        int[] inputs = new int[size];
        for (int i=0; i<size; ++i) {
            System.out.print ("> ");
            inputs[i] = Scan.nextInt();
        }
        bubbleSort (inputs);
        System.out.print ("Sorted: ");
        for (int i=0; i<size; ++i)
            System.out.print (inputs[i] + " ");
    }
}
