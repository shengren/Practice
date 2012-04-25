import java.util.*;

public class Solution {
    public int longestValidParentheses(String s) {
        if (s.length() == 0) return 0;
        
        int min = 0;
        int max = 0;
        int c = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') ++c;
            else --c;
            if (c > max) max = c;
            if (c < min) min = c;
        }
        int[] start = new int[max - min + 1];
        for (int i = 0; i < start.length; ++i) start[i] = -1;
        c = 0 - min;
        s = "$" + s;
        if (s.charAt(1) == '(') start[c] = 0;
        int ret = 0;

        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) == '(') ++c;
            else --c;
            if (start[c] != -1) {
                if (i - start[c] > ret)
                    ret = i - start[c];
            }
            if (i < s.length() - 1) {
                if (s.charAt(i + 1) == '(') {
                    if (start[c] == -1)
                        start[c] = i;
                } else {
                    start[c] = -1;
                }
            }
        }
        
        return ret;
    }
}