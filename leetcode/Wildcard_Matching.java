import java.util.*;

public class Solution {
    String X;
    String Y;
    int[] a;
    HashMap<Integer, Boolean> mem;
    boolean check(int x, int y) {
        int key = x * Y.length() + y;
        if (mem.containsKey(key)) return mem.get(key);
        if (y == Y.length()) {
            boolean r = (x == X.length());
            mem.put(key, r);
            return r;
        }
        if (x == X.length()) {
            if (Y.charAt(y) != '*') {
                mem.put(key, false);
                return false;
            } else {
                boolean r = check(x, y + 1);
                mem.put(key, r);
                return r;
            }
        }
        if (Y.charAt(y) != '*') {
            if (Y.charAt(y) == '?' || X.charAt(x) == Y.charAt(y)) {
                boolean r = check(x + 1, y + 1);
                mem.put(key, r);
                return r;
            } else {
                mem.put(key, false);
                return false;
            }
        }
        for (int i = x; i <= X.length(); ++i) {
            if (X.length() - i < a[y]) break;
            if (check(i, y + 1)) {
                mem.put(key, true);
                return true;
            }
        }
        mem.put(key, false);
        return false;
    }
    String compress(String str) {
        char[] cps = new char[str.length()];
        int j = 0;
        for (int i = 0; i < str.length(); ++i) {
            cps[j] = str.charAt(i);
            if (!(j > 0 && cps[j] == '*' && cps[j - 1] == '*')) ++j;
        }
        return new String(Arrays.copyOfRange(cps, 0, j));
    }
    public boolean isMatch(String s, String p) {
        X = s;
        Y = compress(p);
        if (Y.length() > 0) {
            a = new int[Y.length()];
            a[Y.length() - 1] = 0;
            for (int i = Y.length() - 2; i >= 0; --i) {
                a[i] = a[i + 1] + ((Y.charAt(i + 1) != '*') ? 1 : 0);
            }
        }
        mem = new HashMap<Integer, Boolean>();
        return check(0, 0);
    }
}
