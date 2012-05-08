import java.util.*;

public class Solution {
    int nRows;
    int nCols;
    boolean[][] visited;
    int[][] dir;
    boolean solve(int x, int y, int k, char[][] board, String w) {
        if (k == w.length() - 1) {
            return true;
        }
        visited[x][y] = true;
        for (int m = 0; m < 4; ++m) {
            int nx = x + dir[m][0];
            int ny = y + dir[m][1];
            if (nx >= 0 && nx < nRows && ny >= 0 && ny < nCols
                && !visited[nx][ny] && w.charAt(k + 1) == board[nx][ny]) {
                boolean ret = solve(nx, ny, k + 1, board, w);
                if (ret) return true;
            }
        }
        visited[x][y] = false;
        return false;
    }
    public boolean exist(char[][] board, String word) {
        if (word.length() == 0) return true;
        nRows = board.length;
        if (nRows == 0) return false;
        nCols = board[0].length;
        visited = new boolean[nRows][nCols];
        dir = new int[4][2];
        dir[0][0] = -1; dir[0][1] = 0;
        dir[1][0] = 1; dir[1][1] = 0;
        dir[2][0] = 0; dir[2][1] = 1;
        dir[3][0] = 0; dir[3][1] = -1;
        for (int i = 0; i < nRows; ++i)
            for (int j = 0; j < nCols; ++j)
                if (board[i][j] == word.charAt(0)) {
                    boolean res = solve(i, j, 0, board, word);
                    if (res) return true;
                }
        return false;
    }
}
