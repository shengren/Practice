import java.util.*;

public class Solution {
    public int reverse(int x) {
        if (x == 0) return 0;
        boolean nagtive = (x < 0);
        x = Math.abs(x);
        int ret = 0;
        while (x > 0) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        if (nagtive) ret = -ret;
        return ret;
    }
}