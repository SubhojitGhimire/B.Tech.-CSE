class LrgNumOfDivisors {
    public static void main (String[] args) {
        int CountStore = 1, NumberStore = 1;
        int Count;
        int UpperBound = 10000;
        for (int i=UpperBound; i>=(UpperBound-UpperBound/3); --i) {
            Count = 0;
            for (int j=1; j<=i; ++j) {
                if (i%j == 0)
                    ++Count;
            }
            if (Count > CountStore) {
                NumberStore = i;
                CountStore = Count;
            }
        }
        System.out.println ("Number " + NumberStore + " has " + CountStore + " divisors.");
    }
}