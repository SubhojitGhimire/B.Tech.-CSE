class Counte {
    private int CounterValue = 0;

    public void increment() {
        ++CounterValue;
    }

    public int getValue() {
        return CounterValue;
    }
}

public class Counter {
    public static void main (String[] args) {
        Counte cnt = new Counte();
        System.out.print (cnt.getValue());
        cnt.increment();
        cnt.increment();
        System.out.print (" " + cnt.getValue());
    }
}