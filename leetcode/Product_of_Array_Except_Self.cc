class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ret(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
      ret[i] = ret[i - 1] * nums[i - 1];
    }
    int p = nums.back();
    for (int i = nums.size() - 2; i >= 0; --i) {
      ret[i] *= p;
      p *= nums[i];
    }
    return ret;
  }
};
