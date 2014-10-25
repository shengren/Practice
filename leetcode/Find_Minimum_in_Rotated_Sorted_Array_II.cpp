class Solution {
 public:
  int findMin(vector<int> &num) {
    return FindMin(num, 0, num.size());
  }

 private:
  int FindMin(const vector<int> &num, int a, int b) {
    if (a + 1 == b) return num[a];
    if (num[a] < num[b - 1]) return num[a];
    int m = (a + b) / 2;
    // num[a] >= num[b - 1]
    if (num[a] < num[m - 1]) {
      FindMin(num, m, b);
    } else if (num[a] == num[m - 1]) {
      if (num[m] < num[b - 1]) return num[m];
      else if (num[m] == num[b - 1]) return min(FindMin(num, a, m), FindMin(num, m, b));
      else return FindMin(num, m, b);
    } else {
      return FindMin(num, a, m);
    }
  }
};
