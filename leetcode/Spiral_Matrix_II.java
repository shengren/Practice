import java.util.*;

public class Solution {
    void print(int[][] m, int b, int e, int k) {
        if (b == e) {
            m[b][b] = k;
            return;
        }
        for (int j = b; j < e; ++j) m[b][j] = k++;
        for (int i = b; i < e; ++i) m[i][e] = k++;
        for (int j = e; j > b; --j) m[e][j] = k++;
        for (int i = e; i > b; --i) m[i][b] = k++;
    }
    public int[][] generateMatrix(int n) {
        int[][] m = new int[n][n];
        int k = 1;
        for (int i = 0; i <= n - 1 - i; ++i) {
            print(m, i, n - 1 - i, k);
            k += (n - 2 * i) * 4 - 4;
        }
        return m;
    }
}