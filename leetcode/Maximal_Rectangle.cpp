class Solution {
public:
    // Input is at most 200x200
    int maximalRectangle(vector<vector<char> > &matrix) {
        int num_row = matrix.size();
        if (num_row == 0)
            return 0;
        int num_col = matrix[0].size();
        if (num_col == 0)
            return 0;    
        vector<vector<int> > rightmost(num_row, vector<int>(num_col));
        vector<vector<int> > lowest(num_row, vector<int>(num_col));
        for (int i = 0; i < num_row; ++i) {
            int rightmost_pos = -1;
            for (int j = num_col - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    if (rightmost_pos == -1)
                        rightmost_pos = j;
                } else {
                    rightmost_pos = -1;
                }
                rightmost[i][j] = rightmost_pos;
            }
        }
        for (int j = 0; j < num_col; ++j) {
            int lowest_pos = -1;
            for (int i = num_row - 1; i >= 0; --i) {
                if (matrix[i][j] == '1') {
                    if (lowest_pos == -1)
                        lowest_pos = i;
                } else {
                    lowest_pos = -1;
                }
                lowest[i][j] = lowest_pos;
            }
        }
        int max_rect = 0;
        // O(N^3)
        for (int i = 0; i < num_row; ++i)
            for (int j = 0; j < num_col; ++j)
                if (matrix[i][j] == '1') {
                    int min_row_length = num_col;
                    for (int k = i; k <= lowest[i][j]; ++k) {
                        if (min_row_length > rightmost[k][j] - j + 1)
                            min_row_length = rightmost[k][j] - j + 1;
                        if (max_rect < (k - i + 1) * min_row_length)
                            max_rect = (k - i + 1) * min_row_length;
                    }
                }
        return max_rect;
    }
};
