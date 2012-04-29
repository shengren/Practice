import java.util.*;

public class Solution {
    int index(char c) {
        if (c >= 'A' && c <= 'Z') return c - 'A';
        return c - 'a' + 26;
    }
    boolean okay(int[] has, int[] lim) {
        for (int i = 0; i < has.length; ++i)
            if (has[i] < lim[i])
                return false;
        return true;
    }
    public String minWindow(String S, String T) {
        int[] lim = new int[26 + 26];  // 'A'..'Z' 'a'..'z'
        for (int i = 0; i < T.length(); ++i) {
            lim[index(T.charAt(i))]++;
        }
        int[] has = new int[26 + 26];
        int[] next = new int[S.length()];
        int start = -1;
        int prev = -1;
        String ret = "";
        for (int i = 0; i < S.length(); ++i) {
            char s = S.charAt(i);
            if (T.indexOf(s) >= 0) {
                if (start == -1) start = i;
                if (prev != -1) next[prev] = i;
                prev = i;
                has[index(s)]++;
                int x = index(S.charAt(start));
                while (has[x] > lim[x]) {
                    has[x]--;
                    start = next[start];
                    x = index(S.charAt(start));
                }
                if (okay(has, lim)) {
                    if (ret.length() == 0 || ret.length() > i - start + 1)
                        ret = S.substring(start, i + 1);
                }
            }
        }
        return ret;
    }
}