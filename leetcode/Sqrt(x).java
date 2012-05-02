import java.util.*;

public class Solution {
    public int sqrt(int x) {
        if (x <= 1) return x;
        int a = 0;
        int b = x;
        while (a + 1 < b) {
            int m = (a + b) / 2;
            if (m <= x / m) a = m;
            else b = m;
        }
        return a;
    }
}