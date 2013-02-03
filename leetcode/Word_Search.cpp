int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
    int num_row;
    int num_col;
    bool find(vector<vector<char> > &board, int ridx, int cidx,
              string word, int idx) {
        if (board[ridx][cidx] != word[idx]) {
            return false;
        } else {
            if (idx + 1 == word.length())  // no need to search next character
                return true;
        }
        board[ridx][cidx] = '.';
        for (int k = 0; k < 4; ++k) {
            int new_ridx = ridx + dir[k][0];
            int new_cidx = cidx + dir[k][1];
            if (new_ridx >= 0 && new_ridx < num_row &&
                new_cidx >= 0 && new_cidx < num_col &&
                find(board, new_ridx, new_cidx, word, idx + 1))
                return true;
        }
        board[ridx][cidx] = word[idx];
        return false;
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word == "")
            return true;
        num_row = board.size();
        if (num_row == 0)
            return false;
        num_col = board[0].size();
        if (num_col == 0)
            return false;
        for (int i = 0; i < num_row; ++i)
            for (int j = 0; j < num_col; ++j)
                if (find(board, i, j, word, 0))
                    return true;
        return false;
    }
};
