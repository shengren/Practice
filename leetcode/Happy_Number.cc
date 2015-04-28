class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> ht;

    while (n != 1) {
      ht.insert(n);

      int s = 0;
      while (n > 0) {
        s += square[n % 10];
        n /= 10;
      }
      if (ht.find(s) != ht.end()) return false;

      n = s;
    }

    return true;
  }

  Solution() {
    for (int k = 0; k <= 9; ++k)
      square[k] = k * k;
  }

 private:
  int square[10];
};
