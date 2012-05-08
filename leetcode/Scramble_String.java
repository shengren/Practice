import java.util.*;

public class Solution {
    public boolean isScramble(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        int n = s1.length();
        if (n == 1) return s1.equals(s2);
        int[] ct = new int[26];
        for (int i = 0; i < n; ++i) ct[s1.charAt(i) - 'a']++;
        for (int i = 0; i < n; ++i) ct[s2.charAt(i) - 'a']--;
        for (int i = 0; i < 26; ++i)
            if (ct[i] != 0)
                return false;
        for (int i = 1; i < n; ++i) {
            boolean res = (isScramble(s1.substring(0, i), s2.substring(0, i)) && isScramble(s1.substring(i), s2.substring(i))) ||
                          (isScramble(s1.substring(0, i), s2.substring(n - i)) && isScramble(s1.substring(i), s2.substring(0, n - i)));
            if (res) return true;
        }
        return false;
    }
}