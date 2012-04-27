import java.util.*;

public class Solution {
    public int maxSubArray(int[] A) {
        int max_elem = Integer.MIN_VALUE;
        int max_sum = Integer.MIN_VALUE;
        int sum = 0;
        for (int i = 0; i < A.length; ++i) {
            if (A[i] > max_elem) max_elem = A[i];
            if (sum + A[i] > 0) sum += A[i];
            else sum = 0;
            if (max_sum < sum) max_sum = sum;
        }
        if (max_elem <= 0) return max_elem;
        return max_sum;
    }
}
