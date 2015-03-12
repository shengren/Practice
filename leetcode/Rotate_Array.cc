class Solution {
 public:
  void rotate(int nums[], int n, int k) {
    if (n < 2) return;
    k %= n;
    if (k == 0) return;

    vector<bool> done(n, false);
    for (int i = 0; i < n; ++i) {
      if (!done[i]) {
        int j = i;
        int t = nums[i];
        do {
          j = (j + k) % n;
          int next_t = nums[j];
          nums[j] = t;
          done[j] = true;
          t = next_t;
        } while (j != i);
      }
    }
  }
};
