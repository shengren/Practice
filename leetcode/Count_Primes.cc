class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) return 0;

    vector<bool> is_prime(n, true);
    int ret = 1;  // 2
    for (int x = 3; x < n; x += 2)
      if (is_prime[x]) {
        ++ret;
        if (x * x < n) {
          for (int y = x + x; y < n; y += x)
            is_prime[y] = false;
        }
      }

    return ret;
  }
};
