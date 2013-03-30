public class CombinationGenerator {
    private int[] a;
    private int n;
    private int r;
    private BigInteger numLeft;
    private BigInteger total;

    public CombinationGenerator(int n, int r) {
        this.n = n;
        this.r = r;
        a = new int[r];
        BigInteger nFact = getFactorial(n);
        BigInteger rFact = getFactorial(r);
        BigInteger nminusrFact = getFactorial(n - r);
        total = nFact.divide(rFact.multiply(nminusrFact));
        reset();
    }

    public void reset() {
        for (int i = 0; i < a.length; i++)
            a[i] = i;
        numLeft = total;
    }

    public boolean hasMore() {
        return numLeft.compareTo(BigInteger.ZERO) == 1;
    }

    private static BigInteger getFactorial(int n) {
        BigInteger fact = BigInteger.ONE;
        for (int i = n; i > 1; i--)
            fact = fact.multiply(new BigInteger(Integer.toString(i)));
        return fact;
    }

    public int[] getNext() {
        if (numLeft.equals(total)) {
            numLeft = numLeft.subtract(BigInteger.ONE);
            return a;
        }
        int i = r - 1;
        while (a[i] == n - r + i)
            i--;
        a[i] = a[i] + 1;
        for (int j = i + 1; j < r; j++)
            a[j] = a[i] + j - i;
        numLeft = numLeft.subtract(BigInteger.ONE);
        return a;
    }
}

public class PermutationGenerator {
    private int[] a;
    private long numLeft;
    private long total;

    public PermutationGenerator(int n) {
        a = new int[n];
        total = getFactorial(n);
        reset();
    }

    public void reset() {
        for (int i = 0; i < a.length; i++)
            a[i] = i;
        numLeft = total;
    }

    public boolean hasMore() {
        return numLeft == 0;
    }

    private static long getFactorial(int n) {
        long fact = 1;
        for (int i = n; i > 1; i--) 
            fact = fact * i;
        return fact;
    }

    public int[] getNext() {
        if (numLeft == total) {
            numLeft--;
            return a;
        }
        int temp;
        int j = a.length - 2;
        while (a[j] > a[j + 1])
            j--;
        int k = a.length - 1;
        while (a[j] > a[k])
            k--;
        temp = a[k];
        a[k] = a[j];
        a[j] = temp;
        int r = a.length - 1;
        int s = j + 1;
        while (r > s) {
            temp = a[s];
            a[s++] = a[r];
            a[r--] = temp;
        }
        numLeft--;
        return a;
    }
}