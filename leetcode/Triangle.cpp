class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int num_rows = triangle.size();
        if (num_rows == 0)
            return 0;
        if (num_rows == 1)
            return triangle[0][0];
        
        vector<int> min_sum(num_rows);
        for (int j = 0; j < num_rows; ++j)
            min_sum[j] = triangle[num_rows - 1][j];
        for (int i = num_rows - 2; i >= 0; --i)
            for (int j = 0; j <= i; ++j) {  // <= not <
                if (min_sum[j] < min_sum[j + 1])
                    min_sum[j] += triangle[i][j];
                else
                    min_sum[j] = min_sum[j + 1] + triangle[i][j];
            }
        
        return min_sum[0];
    }
};
