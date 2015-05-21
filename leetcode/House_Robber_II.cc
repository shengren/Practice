class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 0) return 0;
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);
    if (n == 3) return max(max(nums[0], nums[1]), nums[2]);

    return max(nums[0] + robLine(nums, 2, n - 3), robLine(nums, 1, n - 1));
  }

 private:
  int robLine(const vector<int> &nums, int s, int n) {
    vector<int> best(n);
    best[0] = nums[s];
    for (int i = 1; i < n; ++i)
      best[i] = max(best[i - 1], nums[s + i] + (i >= 2 ? best[i - 2] : 0));
    return best[n - 1];
  }
};
