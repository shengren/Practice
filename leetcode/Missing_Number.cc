class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int last = -1;
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] != i && nums[i] != -1) {
        int t = -1;
        int j = i;
        do {
          if (j == nums.size())
            swap(t, last);
          else
            swap(t, nums[j]);
          j = t;
        } while (t != -1);
      }
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == -1)
        return i;
    return nums.size();
  }
};
