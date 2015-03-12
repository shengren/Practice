class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ret = 0;
    while (n > 0) {
      ret += n & 1;
      n >>= 1;
    }
    return ret;
  }
};
