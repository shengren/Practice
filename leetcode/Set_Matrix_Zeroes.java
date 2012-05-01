import java.util.*;

public class Solution {
    public void setZeroes(int[][] matrix) {
        int x = 987654321;
        int r = matrix.length;
        int c = matrix[0].length;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < r; ++k)
                        if (matrix[k][j] != 0)
                            matrix[k][j] = x;
                    for (int k = 0; k < c; ++k)
                        if (matrix[i][k] != 0)
                            matrix[i][k] = x;
                }
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (matrix[i][j] == x) {
                    matrix[i][j] = 0;
                }
    }
}