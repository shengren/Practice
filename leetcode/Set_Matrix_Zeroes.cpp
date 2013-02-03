class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int num_row = matrix.size();
        if (num_row == 0)
            return;
        int num_col = matrix[0].size();
        // The smallest integer that does not exist in the matrix can be found
        // in O(number of elements in matrix) (linear).
        int magic_num = 987654321;//numeric_limits<int>::min();
        for (int i = 0; i < num_row; ++i)
            for (int j = 0; j < num_col; ++j)
                if (matrix[i][j] == 0) {
                    for (int r = 0; r < i; ++r)
                        if (matrix[r][j] != 0)
                            matrix[r][j] = magic_num;
                    for (int r = i + 1; r < num_row; ++r)
                        if (matrix[r][j] != 0)
                            matrix[r][j] = magic_num;
                    for (int c = 0; c < j; ++c)
                        if (matrix[i][c] != 0)
                            matrix[i][c] = magic_num;
                    for (int c = j + 1; c < num_col; ++c)
                        if (matrix[i][c] != 0)
                            matrix[i][c] = magic_num;
                }
        for (int i = 0; i < num_row; ++i)
            for (int j = 0; j < num_col; ++j)
                if (matrix[i][j] == magic_num)
                    matrix[i][j] = 0;
    }
};
