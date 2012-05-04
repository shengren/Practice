import java.util.*;

public class Solution {
    boolean[][] row;
    boolean[][] col;
    boolean[][] cel;
    int[] blanks;
    int nblanks;
    boolean solve(int k, char[][] board) {
        if (k == nblanks) return true;
        int x = blanks[k] / 9;
        int y = blanks[k] % 9;
        int z = x / 3 * 3 + y / 3;
        for (int i = 0; i < 9; ++i)
            if (!row[x][i] && !col[y][i] && !cel[z][i]) {
                row[x][i] = col[y][i] = cel[z][i] = true;
                board[x][y] = (char)('1' + i);
                boolean res = solve(k + 1, board);
                if (res) return true;
                row[x][i] = col[y][i] = cel[z][i] = false;
            }
        return false;
    }
    public void solveSudoku(char[][] board) {
        blanks = new int[81];
        nblanks = 0;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == '.') {
                    blanks[nblanks++] = i * 9 + j;
                }
        row = new boolean[9][9];
        col = new boolean[9][9];
        cel = new boolean[9][9];
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.') {
                    row[i][board[i][j] - '1'] = true;
                }
        for (int j = 0; j < 9; ++j)
            for (int i = 0; i < 9; ++i)
                if (board[i][j] != '.') {
                    col[j][board[i][j] - '1'] = true;
                }
        for (int k = 0; k < 9; ++k) {
            for (int i = k / 3 * 3; i < (k / 3 + 1) * 3; ++i)
                for (int j = k % 3 * 3; j < (k % 3 + 1) * 3; ++j)
                    if (board[i][j] != '.') {
                        cel[k][board[i][j] - '1'] = true;
                    }
        }
        solve(0, board);
    }
}
