class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (t < 0) return false;  // For negative t case
    map<long long, int> m;  // long long is for INT_MAX + 1 case
    for (int i = 0; i < nums.size(); ++i) {
      if (i > k) {
        auto kv = m.find(nums[i - k - 1]);
        if (kv->second == 1)
          m.erase(kv);
        else
          --kv->second;
      }
      if (m.lower_bound((long long)nums[i] - t) !=
          m.upper_bound((long long)nums[i] + t))
        return true;
      ++m[nums[i]];
    }
    return false;
  }
};
