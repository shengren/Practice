import java.util.*;

public class MagicCandy {
    int findK(int x) {
        long k = ((long)Math.sqrt(4 * (double)x + 1) - 1) / 2;
        if (k * (k + 1) < x) ++k;
        return (int)k;
    }
    public int whichOne(int n) {
        int x = n;
        int ct = 0;
        while (x > 1) {
            x -= (int)Math.sqrt(x);
            ++ct;
        }
        int ans = 1;
        while (ct > 0) {
            int k = findK(ans);
            ans += k;
            --ct;
        }
        return ans;
    }
}