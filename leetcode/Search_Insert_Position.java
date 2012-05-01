import java.util.*;

public class Solution {
    public int searchInsert(int[] A, int target) {
        if (target <= A[0]) return 0;
        if (target > A[A.length - 1]) return A.length;
        int a = 0;
        int b = A.length - 1;
        while (a + 1 < b) {
            int m = (a + b) / 2;
            if (A[m] >= target) b = m;
            else a = m;
        }
        return b;
    }
}
