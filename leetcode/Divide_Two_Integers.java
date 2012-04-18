import java.util.*;

public class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        boolean negative = false;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            negative = true;
        long a = dividend;
        a = Math.abs(a);
        long b = divisor;
        b = Math.abs(b);
        long res = 0;
        for (long k = 31; k >= 0; --k) {
            if (a >= (b << k)) {
                a -= (b << k);
                res += (1L << k);
            }
        }
        if (negative) res = 0 - res;
        return (int)res;
    }
}
