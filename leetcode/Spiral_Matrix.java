import java.util.*;

public class Solution {
    void print(int[][] m, int t, int b, int l, int r, ArrayList<Integer> res) {
        if (t == b) {
            for (int j = l; j <= r; ++j) res.add(m[t][j]);
        } else if (l == r) {
            for (int i = t; i <= b; ++i) res.add(m[i][l]);
        } else {
            for (int j = l; j < r; ++j) res.add(m[t][j]);
            for (int i = t; i < b; ++i) res.add(m[i][r]);
            for (int j = r; j > l; --j) res.add(m[b][j]);
            for (int i = b; i > t; --i) res.add(m[i][l]);
        }
    }
    public ArrayList<Integer> spiralOrder(int[][] matrix) {
        ArrayList<Integer> ret = new ArrayList<Integer>();
        int r = matrix.length;
        if (r == 0) return ret;
        int c = matrix[0].length;
        for (int i = 0; i <= r - 1 - i; ++i) {
            int j = i;
            if (j > c - 1 - j) break;
            print(matrix, i, r - 1 - i, j, c - 1 -j, ret);
        }
        return ret;
    }
}