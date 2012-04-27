import java.util.*;

public class Solution {
    public int minPathSum(int[][] grid) {
        int nrow = grid.length;
        if (nrow == 0) return 0;
        int ncol = grid[0].length;
        
        int[][] s = new int[nrow][ncol];
        for (int[] row : s)
            Arrays.fill(row, Integer.MAX_VALUE);
        s[0][0] = grid[0][0];

        for (int d = 0; d <= nrow + ncol - 2; ++d) {
            for (int r = 0; r <= d; ++r) {
                int c = d - r;
                if (r >= 0 && r < nrow && c >= 0 && c < ncol) {
                    if (r < nrow - 1 && s[r + 1][c] > s[r][c] + grid[r + 1][c])
                        s[r + 1][c] = s[r][c] + grid[r + 1][c];
                    if (c < ncol - 1 && s[r][c + 1] > s[r][c] + grid[r][c + 1])
                        s[r][c + 1] = s[r][c] + grid[r][c + 1];
                }
            }
        }
        
        return s[nrow - 1][ncol - 1];
    }
}
