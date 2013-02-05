class Solution {
    vector<vector<string> > solutions;
    void place(int n, int k, vector<string> &board) {
        if (k == n) {
            solutions.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (k > 0) {
                bool ok = true;
                for (int j = 0; j < k; ++j) {
                    if (board[j][i] == 'Q') {  // north
                        ok = false;
                        break;
                    }
                    if (i - (k - j) >= 0 && 
                        board[j][i - (k - j)] == 'Q') {  // northwest
                        ok = false;
                        break;
                    }
                    if (i + (k - j) < n && 
                        board[j][i + (k - j)] == 'Q') {  // northeast
                        ok = false;
                        break;
                    }
                }
                if (!ok)
                    continue;
            }
            board[k][i] = 'Q';
            place(n, k + 1, board);
            board[k][i] = '.';
        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        solutions.clear();
        if (n == 0)
            return solutions;
        vector<string> board(n);
        for (int i = 0; i < n; ++i) {
            board[i] = "";
            for (int j = 0; j < n; ++j)
                board[i] += '.';
        }
        place(n, 0, board);
        return solutions;
    }
};
