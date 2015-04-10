class Solution {
 public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty() || grid[0].empty()) return 0;

    int ret = 0;
    nrow = grid.size();
    ncol = grid[0].size();

    for (int i = 0; i < nrow; ++i)
      for (int j = 0; j < ncol; ++j)
        if (grid[i][j] == '1') {
          fill(grid, i, j);
          ++ret;
        }

    return ret;
  }

 private:
  int nrow;
  int ncol;
  int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  void fill(vector<vector<char>> &grid, int r, int c) {
    queue<pair<int, int>> q;
    
    grid[r][c] = '2';
    q.push(make_pair(r, c));
    
    while (!q.empty()) {
      pair<int, int> cur = q.front();
      q.pop();
      
      for (int k = 0; k < 4; ++k) {
        int nr = cur.first + dir[k][0];
        int nc = cur.second + dir[k][1];
        if (nr >= 0 && nr < nrow && nc >= 0 && nc < ncol && grid[nr][nc] == '1') {
          grid[nr][nc] = '2';
          q.push(make_pair(nr, nc));
        }
      }
    }
  }
};
