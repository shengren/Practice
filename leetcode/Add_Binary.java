import java.util.*;

public class Solution {
    public String addBinary(String a, String b) {
        if (a.length() == 0) return b;
        if (b.length() == 0) return a;
        a = new StringBuffer(a).reverse().toString();
        b = new StringBuffer(b).reverse().toString();
        int p = 0;
        int r = 0;
        StringBuffer res = new StringBuffer("");
        while (p < a.length() && p < b.length()) {
            int s = a.charAt(p) - '0' + b.charAt(p) - '0' + r;
            res.append((s % 2 == 0) ? "0" : "1");
            r = (s > 1) ? 1 : 0;
            ++p;
        }
        while (p < a.length()) {
            int s = a.charAt(p) - '0' + r;
            res.append((s % 2 == 0) ? "0" : "1");
            r = (s > 1) ? 1 : 0;
            ++p;
        }
        while (p < b.length()) {
            int s = b.charAt(p) - '0' + r;
            res.append((s % 2 == 0) ? "0" : "1");
            r = (s > 1) ? 1 : 0;
            ++p;
        }
        if (r == 1) res.append("1");
        return res.reverse().toString();
    }
}
