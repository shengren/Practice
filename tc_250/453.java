/*
LSR 11-09-04

Enumerate and then fiter by set. Don't know if there is a smarter way to solve.
*/

import java.util.*;

public class TheBasketballDivOne {
    Integer[] ans;
    int n, m;
    Set<String> set = new HashSet<String>();

    public int find(int n, int m) {
    	this.n = n;
    	this.m = m;
    	ans = new Integer[n];
        for (int i = 0; i < n; ++i) ans[i] = 0;

        f(0, 1);

    	return set.size();
    }

    void f(int a, int b) {
        if (a == n - 1 && b == n) {
            check();
            return;
        }

        ans[a] += 2;
        if (b < n - 1) f(a, b + 1);
        else f(a + 1, a + 2);
        ans[a] -= 2;

        ans[a] += 1;
        ans[b] += 1;
        if (b < n - 1) f(a, b + 1);
        else f(a + 1, a + 2);
        ans[a] -= 1;
        ans[b] -= 1;

        ans[b] += 2;
        if (b < n - 1) f(a, b + 1);
        else f(a + 1, a + 2);
        ans[b] -= 2;
    }

    void check() {
        Integer[] key = new Integer[ans.length];
        System.arraycopy(ans, 0, key, 0, ans.length);
        Arrays.sort(key, Collections.reverseOrder());
        if (key[0] != m) return;
        String skey = "";
        for (int i = 0; i < key.length; ++i)
            skey += Integer.toString(key[i]);
        set.add(skey);
    }
}