import java.util.*;

public class Solution {
    public int climbStairs(int n) {
        if (n <= 1) return 1;
        int[] c = new int[3];
        c[0] = c[1] = 1;
        for (int i = 2; i <= n; ++i) {
            c[2] = c[0] + c[1];
            c[0] = c[1];
            c[1] = c[2];
        }
        return c[1];
    }
}
