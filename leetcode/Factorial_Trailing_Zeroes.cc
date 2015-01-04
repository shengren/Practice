class Solution {
 public:
  int trailingZeroes(int n) {
    int ret = 0;
    long long p = 5;
    while (n >= p) {
      ret += n / p;
      p *= 5;
    }
    return ret;
  }
};