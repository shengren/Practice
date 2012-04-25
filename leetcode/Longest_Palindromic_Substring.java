import java.util.*;

public class Solution {
    public String longestPalindrome(String s) {
        String ret = "";
        // odd
        for (int i = 0; i < s.length(); ++i) {
            int limit = Math.min(i, s.length() - 1 - i);
            int j = 1;
            while (j <= limit && s.charAt(i - j) == s.charAt(i + j)) ++j;
            if (2 * j - 1 > ret.length()) ret = s.substring(i - j + 1, i + j);
        }
        // even
        for (int i = 0; i < s.length() - 1; ++i)
            if (s.charAt(i) == s.charAt(i + 1)) {
                int limit = Math.min(i, s.length() - 2 - i);
                int j = 1;
                while (j <= limit && s.charAt(i - j) == s.charAt(i + 1 + j)) ++j;
                if (2 * j > ret.length()) ret = s.substring(i - j + 1, i + j + 1);
            }
        return ret;
    }
}