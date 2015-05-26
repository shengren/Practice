class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> dict;
    for (auto v : nums) {
      if (dict.find(v) != dict.end()) return true;
      dict.insert(v);
    }
    return false;
  }
};
