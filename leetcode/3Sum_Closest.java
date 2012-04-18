import java.util.*;

public class Solution {
    public int threeSumClosest(int[] num, int target) {
        // input size < 3?
        Arrays.sort(num);
        int n = num.length;
        HashMap<Integer, Integer> ht = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; ++i) {
            if (ht.containsKey(num[i])) {
                ht.put(num[i], ht.get(num[i]) + 1);
            } else {
                ht.put(num[i], 1);
            }
        }
        int lowDiff = Math.abs(target - num[0] - num[1] - num[2]);
        int highDiff = Math.abs(target - num[n - 1] - num[n - 2] - num[n - 3]);
        int bound = Math.min(lowDiff, highDiff);
        for (int d = 0; d < bound; ++d) {
            int test = target + d;
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j) {
                    int r = test - num[i] - num[j];
                    if (r < num[j]) continue;
                    int ct = 1;
                    if (r == num[j]) ++ct;
                    if (r == num[i]) ++ct;
                    if (ht.containsKey(r)) {
                        int ct_in = ht.get(r);
                        if (ct_in >= ct) return test;
                    }
                }
            if (d == 0) continue;
            test = target - d;
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j) {
                    int r = test - num[i] - num[j];
                    if (r < num[j]) continue;
                    int ct = 1;
                    if (r == num[j]) ++ct;
                    if (r == num[i]) ++ct;
                    if (ht.containsKey(r)) {
                        int ct_in = ht.get(r);
                        if (ct_in >= ct) return test;
                    }
                }
        }
        return (lowDiff < highDiff) ? (num[0] + num[1] + num[2]) : (num[n - 1] + num[n - 2] + num[n - 3]);
    }
}
