import java.util.*;

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int limit = s.length();
        for (int k = limit; k >= 1; --k)
            for (int i = 0; i + k - 1 < s.length(); ++i) {
                boolean flag = true;
                int set = 0;
                for (int j = i; j <= i + k - 1; ++j) {
                    int b = s.charAt(j) - 'a';
                    if ((set & (1 << b)) != 0) {
                        flag = false;
                        break;
                    }
                    set |= (1 << b);
                }
                if (flag) return k;
            }
        return 0;
    }
}