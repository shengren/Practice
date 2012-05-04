import java.util.*;

public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int r = obstacleGrid.length;
        int c = obstacleGrid[0].length;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[r - 1][c - 1] == 1) return 0;
        int[][] np = new int[r][c];
        np[0][0] = 1;
        for (int k = 0; k < r + c - 2; ++k) {
            for (int i = 0; i < r; ++i) {
                int j = k - i;
                if (j >= 0 && j < c && obstacleGrid[i][j] == 0) {
                    if (j + 1 < c && obstacleGrid[i][j + 1] == 0)
                        np[i][j + 1] += np[i][j];
                    if (i + 1 < r && obstacleGrid[i + 1][j] == 0)
                        np[i + 1][j] += np[i][j];
                }
            }
        }
        return np[r - 1][c - 1];
    }
}
