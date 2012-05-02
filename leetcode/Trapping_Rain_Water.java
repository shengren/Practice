import java.util.*;

public class Solution {
    int solve(int[] A, int b, int e, boolean left_closed, boolean right_closed, int height) {
        if (left_closed && right_closed) {
            int sum = 0;
            for (int i = b; i <= e; ++i) sum += height - A[i];
            return sum;
        }
        int max = 0;
        for (int i = b; i <= e; ++i)
            if (max < A[i])
                max = A[i];
        int[] pos = new int[e - b + 1];
        int npos = 0;
        for (int i = b; i <= e; ++i)
            if (A[i] == max) {
                pos[npos++] = i;
            }
        int sum = 0;
        if (b < pos[0]) {
            sum += solve(A, b, pos[0] - 1, left_closed, true, max);
        }
        if (pos[npos - 1] < e) {
            sum += solve(A, pos[npos - 1] + 1, e, true, right_closed, max);
        }
        for (int i = 1; i < npos; ++i)
            if (pos[i - 1] + 1 < pos[i]) {
                sum += solve(A, pos[i - 1] + 1, pos[i] - 1, true, true, max);
            }
        return sum;
    }
    public int trap(int[] A) {
        if (A.length == 0) return 0;
        int max = 0;
        for (int i = 0; i < A.length; ++i)
            if (max < A[i])
                max = A[i];
        return solve(A, 0, A.length - 1, false, false, max);
    }
}