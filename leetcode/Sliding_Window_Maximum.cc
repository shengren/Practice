class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ret;
    deque<pair<int, int>> buffer;

    for (int i = 0; i < nums.size(); ++i) {
      while (!buffer.empty() && buffer.back().first < nums[i])
        buffer.pop_back();
      buffer.push_back(make_pair(nums[i], i));

      if (i >= k - 1) {
        while (buffer.front().second <= i - k)
          buffer.pop_front();
        ret.push_back(buffer.front().first);
      }
    }

    return ret;
  }
};
