class Solution {
 public:
  int maxProfit(int k, vector<int> &prices) {
    const int n = prices.size();
    if (k < 1 || n < 2) return 0;

    int possible_max = 0;
    for (int i = 1; i < n; ++i)
      possible_max += max(prices[i] - prices[i - 1], 0);
    if (k >= n / 2) return possible_max;

    vector<vector<int>> sl(n);
    for (int i = 2; i < n; ++i) {
      unordered_set<int> has;
      for (int j = i - 1; j >= 1; --j)
        if (prices[j] < prices[i] && has.find(prices[j]) == has.end()) {
          sl[i].push_back(j);
          has.insert(prices[j]);
        }
    }

    vector<vector<int>> d(2, vector<int>(n, 0));

    int smallest = prices[0];
    for (int i = 1; i < n; ++i) {
      d[0][i] = max(d[0][i - 1], prices[i] - smallest);
      smallest = min(smallest, prices[i]);
    }
    if (d[0][n - 1] == possible_max) return possible_max;

    int p = 0;
    int q = 1;
    for (int z = 2; z <= k; ++z) {
      for (int x = 1; x < n; ++x) {
        d[q][x] = max(d[p][x], d[q][x - 1]);
        for (int y : sl[x])
          d[q][x] = max(d[q][x], d[p][y - 1] + (prices[x] - prices[y]));
      }
      p ^= 1;
      q ^= 1;
      if (d[p][n - 1] == possible_max) return possible_max;
    }

    return d[p][n - 1];
  }
};