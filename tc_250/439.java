import java.util.*;

public class PouringWater {
    int[] pow2 = new int[25];

    public int getMinBottles(int N, int K) {
        calculatePow2();
        
        if (N <= K) return 0;

        return f(N, K);
    }

    void calculatePow2() {
        for (int i = 0; i < 25; ++i) {
            pow2[i] = (1 << i);
        }
    }

    int f(int n, int k) {
        if (n == 0) return 0;
        if (k == 1) {
            int x = 24;
            while (x > 0 && pow2[x - 1] >= n) --x;
            return pow2[x] - n;
        }
        int x = 24;
        while (pow2[x] > n) --x;
        return f(n - pow2[x], k - 1);
    }
}