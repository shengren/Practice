class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    // x = a ^ b
    int x = 0;
    for (int i = 0; i < nums.size(); ++i)
      x ^= nums[i];

    // Find the rightmost bit at which a and b are different
    int k = 0;
    while ((x & 1 << k) == 0) ++k;

    // Using the k-th bit to split the input into two
    int a = 0;
    int b = 0;
    for (int i = 0; i < nums.size(); ++i)
      if ((nums[i] & 1 << k) == 0)
        a ^= nums[i];
      else
        b ^= nums[i];

    return {a, b};
  }
};
