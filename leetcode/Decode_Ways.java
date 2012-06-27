public class Solution {
    public int numDecodings(String s) {
        if (s.length() == 0) return 0;
        int[] d = new int[s.length() + 1];
        d[0] = 1;
        for (int i = 0; i < d.length - 1; ++i)
            if (d[i] > 0 && s.charAt(i) != '0') {
                d[i + 1] += d[i];
                if (i + 1 < s.length()) {
                    if ((s.charAt(i) == '1') || 
                        (s.charAt(i) == '2' && s.charAt(i + 1) <= '6'))
                        d[i + 2] += d[i];
                }
            }
        return d[d.length - 1];
    }
}