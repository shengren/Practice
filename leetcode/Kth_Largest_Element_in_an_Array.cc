class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    make_heap(nums.begin(), nums.begin() + k, greater<int>());
    
    for (int i = k; i < nums.size(); ++i)
      if (nums[0] < nums[i]) {
        pop_heap(nums.begin(), nums.begin() + k, greater<int>());
        swap(nums[k - 1], nums[i]);
        push_heap(nums.begin(), nums.begin() + k, greater<int>());
      }
    
    return nums[0];
  }
};
