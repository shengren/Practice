import java.util.*;

public class Solution {
    public double pow(double x, int n) {
        if (n == 0) return 1.0;
        if (x == 0.0) return 0.0;
        boolean np = (n < 0);
        long ln = n;
        ln = Math.abs(ln);
        boolean nr = false;
        if (x < 0.0 && ln % 2 == 1) nr = true;
        x = Math.abs(x);
        double[] base = new double[32];
        base[0] = x;
        for (int i = 1; i < 32; ++i) base[i] = base[i - 1] * base[i - 1];
        double res = 1.0;
        for (int i = 31; i >= 0; i--) {
            while (ln >= (1L << i)) {
                ln -= (1L << i);
                res *= base[i];
            }
        }
        if (np) res = 1.0 / res;
        if (nr) res = -res;
        return res;
    }
}
