typedef pair<int, int> Position;

class Solution {
    bool validate(int r, int c, int x, vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i)
            if (board[i][c] == '0' + x)
                return false;
        for (int j = 0; j < 9; ++j)
            if (board[r][j] == '0' + x)
                return false;
        int br = r / 3;
        int bc = c / 3;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                // Forgot to multiply 3 at first
                if (board[br * 3 + i][bc * 3 + j] == '0' + x)
                    return false;
        return true;
    }
    bool solve(int k, 
               vector<Position> &empty_cells, 
               vector<vector<char> > &board) {
        if (k == empty_cells.size())
            return true;
        int r = empty_cells[k].first;
        int c = empty_cells[k].second;
        for (int x = 1; x <= 9; ++x)
            if (validate(r, c, x, board)) {
                board[r][c] = '0' + x;
                if (solve(k + 1, empty_cells, board))
                    return true;
                board[r][c] = '.';
            }
        return false;
    }
public:
    void solveSudoku(vector<vector<char> > &board) {
        vector<Position> empty_cells;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == '.')
                    empty_cells.push_back(make_pair(i, j));
        solve(0, empty_cells, board);
    }
};
