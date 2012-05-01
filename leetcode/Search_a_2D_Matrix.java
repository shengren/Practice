import java.util.*;

public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int r = matrix.length;
        if (r == 0) return false;
        int c = matrix[0].length;
        if (target < matrix[0][0]) return false;
        int a = 0;
        int b = r - 1;
        while (a + 1 < b) {
            int m = (a + b) / 2;
            if (matrix[m][0] <= target) a = m;
            else b = m - 1;
        }
        int x;
        if (target >= matrix[b][0]) x = b;
        else x = a;
        if (target > matrix[x][c - 1]) return false;
        if (target == matrix[x][c - 1]) return true;
        a = 0;
        b = c - 1;
        while (a <= b) {
            int m = (a + b) / 2;
            if (target == matrix[x][m]) return true;
            else if (target > matrix[x][m]) a = m + 1;
            else b = m - 1;
        }
        return false;
    }
}
