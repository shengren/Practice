class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int num_row = obstacleGrid.size();
        if (num_row == 0)
            return 0;
        int num_col = obstacleGrid[0].size();
        if (num_col == 0)
            return 0;
        if (obstacleGrid[0][0] == 1 || 
            obstacleGrid[num_row - 1][num_col - 1] == 1)
            return 0;
        vector<vector<int> > num_path(
            num_row, vector<int>(num_col, 0));
        num_path[0][0] = 1;
        for (int i = 0; i < num_row; ++i)
            for (int j = 0; j < num_col; ++j)
                if (obstacleGrid[i][j] == 0) {
                    if (j + 1 < num_col)
                        num_path[i][j + 1] += num_path[i][j];
                    if (i + 1 < num_row)
                        num_path[i + 1][j] += num_path[i][j];
                }
        return num_path[num_row - 1][num_col - 1];
    }
};
