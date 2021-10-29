class Multiply {
    private static int a = 10;
    private static int b = 12;

    public void takeNum (int num1, int num2) {
        a = num1;
        b = num2;
    }

    public int multiplyNum () {
        return a*b;
    }
}

public class NonStatic {
    public static void main (String[] args) {
        Multiply m = new Multiply();
        m.takeNum (5, 2);
        int result = m.multiplyNum();
        System.out.println (result);
    }
}