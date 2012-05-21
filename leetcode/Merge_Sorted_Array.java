import java.util.*;

public class Solution {
    public void merge(int A[], int m, int B[], int n) {
        Queue<Integer> q = new LinkedList<Integer>();
        int a = 0;
        int b = 0;
        while (a < m + n) {
            if (b < n) {
                if (q.size() > 0) {
                    if (a < m) q.add(A[a]);
                    if (B[b] <= q.peek()) {
                        A[a] = B[b];
                        ++b;
                    } else {
                        A[a] = q.poll();
                    }
                } else {
                    if (a < m && B[b] <= A[a]) {
                        q.add(A[a]);
                        A[a] = B[b];
                        ++b;
                    } else if (a >= m) {
                        A[a] = B[b];
                        ++b;
                    }
                }
            } else {
                if (q.size() > 0) {
                    if (a < m) q.add(A[a]);
                    A[a] = q.poll();
                }
            }
            ++a;
        }
    }
}