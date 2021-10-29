import java.util.Scanner;

class Eggs {
    public static void main (String[] args) {
        Scanner Scan = new Scanner(System.in);
        System.out.print ("How many eggs do you have?\n> ");
        int TotalEggs = Scan.nextInt();
        if (!(TotalEggs >= 144)) {
            System.out.println ("You have " + TotalEggs/12 + " dozen of Eggs and " + TotalEggs%12 + " Eggs left over.");
        }
        else {
            int GrossEggs = TotalEggs/144;
            int DozenEggs = (TotalEggs-GrossEggs*144)/12;
            int LeftEggs = TotalEggs-GrossEggs*144-DozenEggs*12;
            System.out.println ("Your number of eggs is " + GrossEggs + " gross, " + DozenEggs + " dozen, and " + LeftEggs);
        }
    }
}