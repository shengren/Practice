class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Row
        for (int i = 0; i < 9; ++i) {
            int bitmap = 0;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                int bit_pos = board[i][j] - '0';
                if ((bitmap & (1 << bit_pos)) != 0)
                    return false;
                else
                    bitmap |= (1 << bit_pos);
            }
        }
        // Column
        for (int j = 0; j < 9; ++j) {
            int bitmap = 0;
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] == '.')
                    continue;
                int bit_pos = board[i][j] - '0';
                if ((bitmap & (1 << bit_pos)) != 0)
                    return false;
                else
                    bitmap |= (1 << bit_pos);
            }
        }
        // Cell
        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9; j += 3) {
                int bitmap = 0;
                for (int u = i; u < i + 3; ++u)
                    for (int v = j; v < j + 3; ++v) {
                        if (board[u][v] == '.')
                            continue;
                        int bit_pos = board[u][v] - '0';
                        if ((bitmap & (1 << bit_pos)) != 0)
                            return false;
                        else
                            bitmap |= (1 << bit_pos);
                    }
            }
        return true;
    }
};
