import java.util.*;

public class Solution {
    public String strStr(String haystack, String needle) {
        if (needle.length() == 0) return haystack;
        int[] next = new int[needle.length()];
        next[0] = -1;
        int j = -1;
        for (int i = 1; i < needle.length(); ++i) {
            while (j >= 0 && needle.charAt(i) != needle.charAt(j + 1))
                j = next[j];
            if (needle.charAt(i) == needle.charAt(j + 1))
                ++j;
            next[i] = j;
        }

        int offset = -1;
        j = -1;
        for (int i = 0; i < haystack.length(); ++i) {
            while (j >= 0 && haystack.charAt(i) != needle.charAt(j + 1))
                j = next[j];
            if (haystack.charAt(i) == needle.charAt(j + 1))
                ++j;
            if (j == needle.length() - 1) {
                offset = i + 1 - needle.length();
                break;
            }
        }

        if (offset == -1) return null;
        return haystack.substring(offset);
    }
}
