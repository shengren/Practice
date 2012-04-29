import java.util.*;

public class Solution {
    public void nextPermutation(int[] num) {
        int p = -1;
        int q = -1;
        for (int i = num.length - 1; i > 0; --i) {
            for (int j = i - 1; j >= 0; --j) {
                if (num[i] > num[j]) {
                    if (p == -1) {
                        p = j;
                        q = i;
                    } else if (j > p) {
                        p = j;
                        q = i;
                    } else if (j == p && num[i] < num[q]) {
                        p = j;
                        q = i;
                    }
                }
            }
        }
        if (p != -1) {
            int t = num[p];
            num[p] = num[q];
            num[q] = t;
            Arrays.sort(num, p + 1, num.length);
            return;
        }
        for (int i = 0; i < num.length - 1 - i; ++i) {
            int t = num[i];
            num[i] = num[num.length - 1 - i];
            num[num.length - 1 - i] = t;
        }
    }
}