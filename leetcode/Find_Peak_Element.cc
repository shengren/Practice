class Solution {
 public:
  int findPeakElement(const vector<int> &num) {
    if (num.empty()) return -1;
    return FindPeakElement(num, 0, num.size());
  }

 private:
  int FindPeakElement(const vector<int> &num, int a, int b) {
    if (a + 1 == b) return a;
    int m = (a + b) / 2;
    bool left = (m == 0 || num[m - 1] < num[m]);
    bool right = (m == num.size() - 1 || num[m + 1] < num[m]);
    if (left && right) return m;
    if (!left) return FindPeakElement(num, a, m);
    return FindPeakElement(num, m + 1, b);
  }
};
