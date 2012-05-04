import java.util.*;

public class Solution {
    public int uniquePaths(int m, int n) {
        int a = m - 1 + n - 1;
        int b = Math.max(m - 1, n - 1);
        int c = a - b;
        long ret = 1;
        while (a > c && b > 1) {
            ret *= a;
            a--;
            if (ret % b == 0) {
                ret /= b;
                b--;
            }
        }
        while (a > c) {
            ret *= a;
            a--;
        }
        while (b > 1) {
            ret /= b;
            b--;
        }
        return (int)ret;
    }
}
