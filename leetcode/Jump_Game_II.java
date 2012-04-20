import java.util.*;

public class Solution {
    public int jump(int[] A) {
        int[] d = new int[A.length];
        int p = 0;
        Arrays.fill(d, Integer.MAX_VALUE);
        d[0] = 0;
        for (int i = 0; i < A.length; ++i)
            if (i <= p) {
                int q = Math.min(Math.max(p, i + A[i]), A.length - 1);
                for (int j = p + 1; j <= q; ++j) d[j] = d[i] + 1;
                p = q;
            } else {
                break;
            }
        return d[d.length - 1];
    }
}