class Solution {
 public:
  int rob(vector<int> &num) {
    int n = num.size();
    if (n == 0) return 0;

    vector<int> m(n, 0);
    for (int i = 0; i < n; ++i) {
      m[i] = num[i] + (i >= 2 ? m[i - 2] : 0);
      if (i >= 1) m[i] = max(m[i], m[i - 1]);
    }

    return m[n - 1];
  }
};
