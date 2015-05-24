class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ret;
    vector<int> c;
    Search(c, k, n, ret);
    return ret;
  }

 private:
  void Search(vector<int> &c, int k, int n, vector<vector<int>> &ret) {
    if (c.size() == k - 1) {
      if (c.back() < n && n <= 9) {
        c.push_back(n);
        ret.push_back(c);
        c.pop_back();
      }
      return;
    }

    int min_v = c.empty() ? 1 : c.back() + 1;
    int max_v = min(n, 9);
    for (int v = min_v; v <= max_v; ++v) {
      c.push_back(v);
      Search(c, k, n - v, ret);
      c.pop_back();
    }
  }
};
