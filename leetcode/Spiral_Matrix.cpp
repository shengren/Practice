int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> spiral_order;
        int num_row = matrix.size();
        if (num_row == 0)
            return spiral_order;
        int num_col = matrix[0].size();
        if (num_col == 0)
            return spiral_order;
        int x = 0;  // row index
        int y = 0;  // column index
        int k = 0;  // direction
        int up_bound    = 0;
        int down_bound  = num_row - 1;
        int left_bound  = 0;
        int right_bound = num_col - 1;
        for (int i = 0; i < num_row * num_col; ++i) {
            spiral_order.push_back(matrix[x][y]);
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];
            if (ny > right_bound) {
                up_bound += 1;  // Update
                k = 1;
                x += dir[k][0];
                y += dir[k][1];
            } else if (nx > down_bound) {
                right_bound -= 1;  // Update
                k = 2;
                x += dir[k][0];
                y += dir[k][1];
            } else if (ny < left_bound) {
                down_bound -= 1;  // Update
                k = 3;
                x += dir[k][0];
                y += dir[k][1];
            } else if (nx < up_bound) {
                left_bound += 1;  // Update
                k = 0;
                x += dir[k][0];
                y += dir[k][1];
            } else {
                x = nx;
                y = ny;
            }
        }
        return spiral_order;
    }
};
