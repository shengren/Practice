import java.util.*;

public class Solution {
    public int atoi(String str) {
        str = str.trim();
        if (str.length() == 0) return 0;
        boolean neg = false;
        int k = 0;
        if (str.charAt(0) == '+') {
            k = 1;
        } else if (str.charAt(0) == '-') {
            neg = true;
            k = 1;
        } else if ("0123456789".indexOf(str.charAt(0)) == -1) {
            return 0;
        }
        long n = 0;
        while (k < str.length()) {
            char c = str.charAt(k);
            k++;
            if ("0123456789".indexOf(c) == -1) break;
            n = n * 10 + c - '0';
        }
        if (neg) n = -n;
        if (n < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        else if (n > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        else return (int)n;
    }
}