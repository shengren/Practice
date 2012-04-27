import java.util.*;

public class Solution {
    double search(int[] A, int[] B, int ab, int ae, int bb, int be, int k) {
        if (ae - ab > be - bb) {
            int[] C = A; A = B; B = C;
            int t = ab; ab = bb; bb = t;
            t = ae; ae = be; be = t;
        }
        
        if (ab > ae)
            return B[bb + k];

        int am = (ab + ae) / 2;
        int x = A[am];
        int pos = bb - 1;
        if (x > B[bb]) {
            int p = bb;
            int q = be;
            while (p + 1 < q) {
                int m = (p + q) / 2;
                if (x <= B[m]) q = m - 1;
                else p = m;
            }
            if (x > B[q]) pos = q;
            else pos = p;
        }
        
        int small = am - ab + 1 + pos - bb + 1;
        if (k < small) {
            if (ab == ae) {
                if (pos - bb + 1 == k) return x;
                else if (pos - bb + 1 > k) return B[bb + k];
                else return B[bb + k - 1];
            }
            return search(A, B, ab, am, bb, pos, k);
        } else {
            return search(A, B, am + 1, ae, pos + 1, be, k - small);
        }
    }
    public double findMedianSortedArrays(int A[], int B[]) {
        if (A.length > B.length) {
            int[] C = A; A = B; B = C;
        }
        if (A.length == 0) {
            if (B.length == 0) return 0.0;
            int m = B.length / 2;
            if (B.length % 2 == 0) {
                return (B[m - 1] + B[m]) / 2.0;
            } else {
                return B[m];
            }
        }

        int total = A.length + B.length;
        double ret = search(A, B, 0, A.length - 1, 0, B.length - 1, total / 2);
        if (total % 2 == 0) {
            ret += search(A, B, 0, A.length - 1, 0, B.length - 1, total / 2 - 1);
            ret /= 2.0;
        }
        return ret;
    }
}