class Solution {
 public:
  int countDigitOne(int n) {
    int step[10];  // 1, 10, 100, 1000, ...
    step[0] = 1;
    for (int k = 1; k < 10; ++k)
      step[k] = step[k - 1] * 10;

    int sum[10];  // sum[k]: Number of 1 between 0 and step[k] - 1 (inclusive)
    sum[0] = 0;
    for (int k = 1; k < 10; ++k)
      sum[k] = sum[k - 1] * 10 + step[k - 1];

    int res = 0;
    for (int k = 9; k >= 0; --k)
      if (n >= step[k]) {
        int d = n / step[k];  // k-th digit of n
        for (int i = 0; i < d; ++i) {
          res += sum[k];
          if (i == 1) res += step[k];
        }
        n %= step[k];
        if (d == 1) res += n + 1;
      }
    return res;
  }
};
