import java.util.*;

public class Solution {
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
    void solve(int r, int n, char[][] m, ArrayList<String[]> res) {
        if (r == n) {
            String[] x = new String[n];
            for (int i = 0; i < n; ++i) x[i] = new String(m[i]);
            res.add(x);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (okay(r, i, n, m)) {
                m[r][i] = 'Q';
                solve(r + 1, n, m, res);
                m[r][i] = '.';
            }
        }
    }
    public ArrayList<String[]> solveNQueens(int n) {
        ArrayList<String[]> ret = new ArrayList<String[]>();
        char[][] board = new char[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] = '.';
        solve(0, n, board, ret);
        return ret;
    }

/*    public static void main(String[] args) {
        Solution o = new Solution();
        ArrayList<String[]> a = o.solveNQueens(4);
        ListIterator<String[]> it = a.listIterator();
        while (it.hasNext()) {
            String[] x = it.next();
            for (int i = 0; i < x.length; ++i)
                System.out.println(x[i]);
            System.out.println();
        }
    }*/
}