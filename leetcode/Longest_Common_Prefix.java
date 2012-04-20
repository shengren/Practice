import java.util.*;

class ByLength implements Comparator<String> {
    public int compare(String a, String b) {
        if (a.length() == b.length())
            return a.compareTo(b);
        return a.length() - b.length();
    }
}

public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        Arrays.sort(strs, new ByLength());
        String c = strs[0];
        for (int i = 1; i < strs.length; ++i) {
            if (strs[i].equals(strs[i - 1])) continue;
            int k = 0;
            while (k < c.length()) {
                if (strs[i].charAt(k) == c.charAt(k)) ++k;
                else break;
            }
            c = c.substring(0, k);
        }
        return c;
    }
}