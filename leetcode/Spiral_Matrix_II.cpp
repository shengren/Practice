int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int x = 0;
        int y = 0;
        int k = 0;  // direction
        for (int i = 1; i <= n * n; ++i) {
            matrix[x][y] = i;
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && matrix[nx][ny] == 0) {
                x = nx;
                y = ny;
            } else {
                k = (k + 1) % 4;
                x += dir[k][0];
                y += dir[k][1];
            }
        }
        return matrix;
    }
};
