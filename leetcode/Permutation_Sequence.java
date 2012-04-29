import java.util.*;

public class Solution {
    int find(int pos, boolean[] has, int[] base, int[] fact, int n, int k) {
        int lim = fact[pos];
        int x = 0;
        for (int i = 1; i <= n; ++i)
            if (has[i]) {
                if (k <= lim) {
                    k -= lim - fact[pos];
                    x = i;
                    has[i] = false;
                    break;
                } else {
                    lim += fact[pos];
                }
            }
        if (pos == 0) return x;
        return x * base[pos] + find(pos - 1, has, base, fact, n, k);
    }
    public String getPermutation(int n, int k) {
        boolean[] has = new boolean[n + 1];
        for (int i = 1; i <= n; ++i) has[i] = true;
        int[] base = new int[n];
        base[0] = 1;
        for (int i = 1; i < n; ++i) base[i] = base[i - 1] * 10;
        int[] fact = new int[n];
        fact[0] = 1;
        for (int i = 1; i < n; ++i) fact[i] = i * fact[i - 1];

        int res = find(n - 1, has, base, fact, n, k);
        return Integer.toString(res);
    }
}