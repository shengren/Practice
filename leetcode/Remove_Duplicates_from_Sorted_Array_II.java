import java.util.*;

public class Solution {
    public int removeDuplicates(int[] A) {
        if (A.length == 0) return 0;
        int cur = 0;
        int ct = 1;
        for (int i = 1; i < A.length; ++i) {
            if (A[cur] != A[i]) {
                ++cur;
                A[cur] = A[i];
                ct = 1;
            } else if (A[cur] == A[i] && ct == 1) {
                ++cur;
                A[cur] = A[i];
                ct++;
            }
        }
        return cur + 1;
    }
}