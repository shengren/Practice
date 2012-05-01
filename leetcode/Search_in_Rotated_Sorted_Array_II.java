import java.util.*;

public class Solution {
    boolean binarySearch(int[] A, int target, int a, int b) {
        while (a < b) {
            int m = (a + b) / 2;
            if (A[m] == target) return true;
            else if (A[m] > target) b = m;
            else a = m + 1;
        }
        return false;
    }
    public boolean search(int[] A, int target) {
        if (target == A[0] || target == A[A.length - 1]) return true;
        int p = 0;
        int q = A.length - 1;
        if (A[0] == A[A.length - 1]) {
            while (p < A.length && A[p] == A[0]) ++p;
            if (p == A.length) return false;
            while (A[q] == A[A.length - 1]) --q;
        }
        
        if (A[p] > A[q]) {
            int a = p;
            int b = q;
            while (a + 1 < b) {
                int m = (a + b) / 2;
                if (A[m] >= A[p]) a = m;
                if (A[m] <= A[q]) b = m;
            }
            return binarySearch(A, target, p, b) || binarySearch(A, target, b, q + 1);
        } else {
            return binarySearch(A, target, p, q + 1);
        }
    }
}
