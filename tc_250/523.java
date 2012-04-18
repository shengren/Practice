import java.util.*;

public class CountingSeries {
    boolean okay(long x, long a, long b) {
        if (x < a) return true;
        return (x - a) % b != 0;
    }
    public long countThem(long a, long b, long c, long d, long upperBound) {
        long ret = 0;
        if (a <= upperBound) {
            ret += (upperBound - a) / b + 1;
        }
        if (d == 1) {
            if (c <= upperBound && okay(c, a, b)) ++ret;
        } else {
            long x = c;
            while (x <= upperBound) {
                if (okay(x, a, b)) ++ret;
                x *= d;
            }
        }
        return ret;
    }
}