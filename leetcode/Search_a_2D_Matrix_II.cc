class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int num_row = matrix.size();
    int num_col = matrix[0].size();
    return SearchDiagonal(matrix, target, 0, num_row, 0, num_col);
  }

 private:
  bool SearchDiagonal(const vector<vector<int>> &matrix, int target, int rb,
                      int re, int cb, int ce) {
    if (rb == re || cb == ce) return false;
    if (target < matrix[rb][cb]) return false;
    if (re - rb == 1) return SearchRow(matrix, target, rb, cb, ce);
    if (ce - cb == 1) return SearchColumn(matrix, target, cb, rb, re);
    int l = 0;
    int u = min(re - rb, ce - cb);
    while (l + 1 < u) {
      int m = (l + u) / 2;
      if (target < matrix[rb + m][cb + m]) u = m;
      else l = m;
    }
    if (target == matrix[rb + l][cb + l]) return true;
    return SearchDiagonal(matrix, target, rb, rb + u, cb + u, ce) ||
           SearchDiagonal(matrix, target, rb + u, re, cb, cb + u);
  }

  bool SearchRow(const vector<vector<int>> &matrix, int target, int r, int l,
                 int u) {
    while (l + 1 < u) {
      int m = (l + u) / 2;
      if (target < matrix[r][m]) u = m;
      else l = m;
    }
    return target == matrix[r][l];
  }

  bool SearchColumn(const vector<vector<int>> &matrix, int target, int c, int l,
                    int u) {
    while (l + 1 < u) {
      int m = (l + u) / 2;
      if (target < matrix[m][c]) u = m;
      else l = m;
    }
    return target == matrix[l][c];
  }
};
