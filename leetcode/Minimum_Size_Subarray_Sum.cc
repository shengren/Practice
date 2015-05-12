class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    // return nSolution(s, nums);
    
    return nlognSolution(s, nums);
  }

 private:
  int nSolution(int s, const vector<int>& nums) {
    if (nums.empty()) return 0;

    int sum = 0;
    int a = 0;
    int ret = nums.size() + 1;

    for (int b = 0; b < nums.size(); ++b) {
      if (nums[b] >= s) return 1;
      sum += nums[b];
      while (a < b && sum >= s) {
        ret = min(ret, b - a + 1);  // ret > 1 cases
        sum -= nums[a++];
      }
    }

    return (ret == nums.size() + 1) ? 0 : ret;
  }

  int nlognSolution(int s, const vector<int>& nums) {
    if (nums.empty()) return 0;

    vector<int> ps(nums.size());
    for (int i = 0; i < nums.size(); ++i)
      ps[i] = nums[i] + (i > 0 ? ps[i - 1] : 0);

    int ret = nums.size() + 1;

    for (int i = 0; i < ps.size(); ++i)
      if (ps[i] >= s) {
        int j = BinarySearch(ps, i, ps[i] - s);
        ret = min(ret, i - j);
      }

    return (ret == nums.size() + 1) ? 0 : ret;
  }

  int BinarySearch(const vector<int> &ps, int i, int k) {
    if (k < ps[0]) return -1;

    int a = 0;
    int b = i;
    while (a + 1 < b) {
      int m = (a + b) / 2;
      if (ps[m] <= k) a = m;
      else b = m;
    }

    return a;
  }

};
