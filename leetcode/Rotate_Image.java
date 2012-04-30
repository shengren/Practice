import java.util.*;

public class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        if (n == 0) return;
        int x, y;
        if (n % 2 == 1) {
            x = n / 2;
            y = n / 2 + 1;
        } else {
            x = n / 2;
            y = n / 2;
        }
        for (int i = 0; i < x; ++i)
            for (int j = 0; j < y; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = t;
            }
    }
}