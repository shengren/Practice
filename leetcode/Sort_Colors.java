import java.util.*;

public class Solution {
    public void sortColors(int[] A) {
        int r = 0;
        while (r < A.length && A[r] == 0) ++r;
        if (r == A.length) return;
        int b = A.length - 1;
        while (b >= 0 && A[b] == 2) --b;
        if (b < 0) return;
        if (r > b) return;
        int p = r;
        while (p <= b && p < A.length) {
            if (A[p] == 0) {
                A[p] = A[r];
                A[r] = 0;
                ++r;
            } else if (A[p] == 2) {
                A[p] = A[b];
                A[b] = 2;
                --b;
            } else {
                ++p;
            }
            if (p < r) p = r;
        }
    }
}