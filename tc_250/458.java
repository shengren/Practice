import java.util.*;

public class BouncingBalls {
    double res;
    int n, T;
    int[] x;
    boolean[] d = new boolean[12];
    public double expectedBounces(int[] x, int T) {
        Arrays.sort(x);
        n = x.length;
        this.x = x;
        this.T = T;
        res = 0.0;
        gen(0);
        res /= (double)(1 << n);
        return res;
    }

    void gen(int k) {
        if (k == n) {
            res += 0.5 * comp();
            return;
        }
        d[k] = false;
        gen(k + 1);
        d[k] = true;
        gen(k + 1);
    }

    int comp() {
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (d[i]) {
                for (int j = i - 1; j >= 0; --j) {
                    if (!d[j] && (x[i] - x[j]) <= 2 * T) ++ret;
                }
            }
            else {
                for (int j = i + 1; j < n; ++j) {
                    if (d[j] && (x[j] - x[i]) <= 2 * T) ++ret;
                }
            }
        }
        return ret;
    }
}