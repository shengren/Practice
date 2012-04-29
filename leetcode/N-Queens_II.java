import java.util.*;

public class Solution {
    int ret;
    boolean okay(int r, int c, int n, char[][] m) {
        for (int k = 1; r - k >= 0; ++k) {
            if (m[r - k][c] == 'Q')
                return false;
            if (c - k >= 0 && m[r - k][c - k] == 'Q')
                return false;
            if (c + k < n && m[r - k][c + k] == 'Q')
                return false;
        }
        return true;
    }
    void solve(int r, int n, char[][] m) {
        if (r == n) {
            ++ret;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (okay(r, i, n, m)) {
                m[r][i] = 'Q';
                solve(r + 1, n, m);
                m[r][i] = '.';
            }
        }
    }
    public int totalNQueens(int n) {
        char[][] board = new char[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] = '.';
        ret = 0;
        solve(0, n, board);
        return ret;
    }
}