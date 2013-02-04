class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int num_row = grid.size();
        if (num_row == 0)
            return 0;
        int num_col = grid[0].size();
        if (num_col == 0)
            return 0;
        vector<vector<int> > min_sum(
            num_row, 
            vector<int>(num_col, numeric_limits<int>::max())
            );
        min_sum[0][0] = grid[0][0];
        for (int i = 0; i < num_row; ++i)
            for (int j = 0; j < num_col; ++j) {
                if (j + 1 < num_col && 
                    min_sum[i][j + 1] > min_sum[i][j] + grid[i][j + 1])
                    min_sum[i][j + 1] = min_sum[i][j] + grid[i][j + 1];
                if (i + 1 < num_row && 
                    min_sum[i + 1][j] > min_sum[i][j] + grid[i + 1][j])
                    min_sum[i + 1][j] = min_sum[i][j] + grid[i + 1][j];
            }
        return min_sum[num_row - 1][num_col - 1];
    }
};
