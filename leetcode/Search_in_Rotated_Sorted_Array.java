import java.util.*;

public class Solution {
    int binarySearch(int[] A, int target, int a, int b) {
        while (a < b) {
            int m = (a + b) / 2;
            if (A[m] == target) return m;
            else if (A[m] > target) b = m;
            else a = m + 1;
        }
        return -1;
    }
    public int search(int[] A, int target) {
        if (A[0] > A[A.length - 1]) {
            int sec = A.length - 1;
            int a = 0;
            int b = A.length - 1;
            while (a + 1 < b) {
                int m = (a + b) / 2;
                if (A[m] > A[0]) a = m;
                if (A[m] < A[A.length - 1]) b = m;
            }
            int res = binarySearch(A, target, 0, b);
            if (res != -1) return res;
            return binarySearch(A, target, b, A.length);
        } else {
            return binarySearch(A, target, 0, A.length);
        }
    }
}
