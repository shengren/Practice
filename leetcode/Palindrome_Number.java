import java.util.*;

public class Solution {
    int digit(int x, int pos) {
        while (pos > 0) {
            x /= 10;
            pos--;
        }
        return x % 10;
    }
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        int n = 10;
        int lim = 1000000000;
        while (x < lim) {
            lim /= 10;
            --n;
        }
        for (int i = 0; i < n - 1 - i; ++i)
            if (digit(x, i) != digit(x, n - 1 - i))
                return false;
        return true;
    }
}