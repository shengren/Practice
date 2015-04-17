class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int ret = 0;
    int r = n - m + 1;
    int a = m & n;
    for (int k = 0; k <= 30; ++k) {
      int p = 1 << k;
      if (r <= p)
        ret ^= a & p;
    }
    return ret;
  }
};
