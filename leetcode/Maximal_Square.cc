class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int num_row = matrix.size();
    if (num_row == 0) return 0;
    int num_col = matrix[0].size();
    if (num_col == 0) return 0;

    vector<vector<int>> ones(num_row, vector<int>(num_col, 0));
    for (int i = 0; i < num_row; ++i)
      for (int j = 0; j < num_col; ++j)
        ones[i][j] = (matrix[i][j] - '0') + (j == 0 ? 0 : ones[i][j - 1]);
    for (int i = 1; i < num_row; ++i)
      for (int j = 0; j < num_col; ++j)
        ones[i][j] += ones[i - 1][j];

    int side = min(num_row, num_col);
    while (side > 0) {
      for (int i = 0; i + side <= num_row; ++i)
        for (int j = 0; j + side <= num_col; ++j)
          if (matrix[i][j] == '1') {
            int sum = ones[i + side - 1][j + side - 1];
            if (i > 0) sum -= ones[i - 1][j + side - 1];
            if (j > 0) sum -= ones[i + side - 1][j - 1];
            if (i > 0 && j > 0) sum += ones[i - 1][j - 1];
            if (sum == side * side)
              return sum;
          }
      --side;
    }

    return 0;
  }
};
