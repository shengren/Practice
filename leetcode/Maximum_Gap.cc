class Solution {
 public:
  int maximumGap(vector<int> &num) {
    if (num.size() < 2) return 0;
    if (num.size() == 2) return abs(num[0] - num[1]);
    
    int min = INT_MAX;
    int max = INT_MIN;
    for (int x : num) {
      if (min > x) min = x;
      if (max < x) max = x;
    }
    if (min == max) return 0;
    
    int n = num.size() - 2;
    double w = (max - min) / (double)n;
    vector<int> lb(n, -1);
    vector<int> ub(n, -1);
    for (int x : num) {
      if (x == min || x == max) continue;
      int k = (x - min) / w;
      if (lb[k] == -1) {
        lb[k] = ub[k] = x;
      } else {
        if (lb[k] > x) lb[k] = x;
        if (ub[k] < x) ub[k] = x;
      }
    }

    int max_gap = 0;
    int l = min;
    for (int k = 0; k < n; ++k) {
      if (lb[k] != -1) {
        if (max_gap < lb[k] - l) max_gap = lb[k] - l;
        l = ub[k];
      }
    }
    if (max_gap < max - l) max_gap = max - l;
    
    return max_gap;
  }
};