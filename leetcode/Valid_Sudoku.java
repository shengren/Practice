import java.util.*;

public class Solution {
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; ++i) {
            boolean[] u = new boolean[9];
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.') {
                    int x = board[i][j] - '1';
                    if (u[x]) return false;
                    u[x] = true;
                }
        }
        for (int j = 0; j < 9; ++j) {
            boolean[] u = new boolean[9];
            for (int i = 0; i < 9; ++i)
                if (board[i][j] != '.') {
                    int x = board[i][j] - '1';
                    if (u[x]) return false;
                    u[x] = true;
                }
        }
        for (int k = 0; k < 9; ++k) {
            boolean[] u = new boolean[9];
            for (int i = k / 3 * 3; i < (k / 3 + 1) * 3; ++i)
                for (int j = k % 3 * 3; j < (k % 3 + 1) * 3; ++j)
                    if (board[i][j] != '.') {
                        int x = board[i][j] - '1';
                        if (u[x]) return false;
                        u[x] = true;
                    }
        }
        return true;
    }
}
