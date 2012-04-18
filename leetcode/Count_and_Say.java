import java.util.*;

public class Solution {
    public String countAndSay(int n) {
        n--;
        String s = "1";
        while (n > 0) {
            s += "$";
            String gen = "";
            char c = '$';
            int ct = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (i == 0 || s.charAt(i) != s.charAt(i - 1)) {
                    if (i > 0) {
                        gen += Integer.toString(ct);
                        gen += c;
                    }
                    c = s.charAt(i);
                    ct = 1;
                } else {
                    ct++;
                }
            }
            s = gen;
            n--;
        }
        return s;
    }
}
