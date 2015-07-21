class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ret;
    if (nums.empty()) return ret;
    auto range = make_pair(nums[0], nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] + 1 == nums[i]) {
        range.second = nums[i];
      } else {
        ret.push_back(GetString(range));
        range = make_pair(nums[i], nums[i]);
      }
    }
    ret.push_back(GetString(range));
    return ret;
  }

 private:
  string GetString(const pair<int, int> &range) {
    ostringstream oss;
    oss << range.first;
    if (range.first != range.second)
      oss << "->" << range.second;
    return oss.str();
  }
};
