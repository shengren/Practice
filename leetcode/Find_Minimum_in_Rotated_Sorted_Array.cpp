class Solution {
 public:
  int findMin(vector<int> &num) {
    return FindMin(num, 0, num.size());
  }

 private:
  int FindMin(const vector<int> &num, int a, int b) {
    if (num[a] <= num[b - 1]) return num[a];
    int m = (a + b) / 2;
    return min(FindMin(num, a, m), FindMin(num, m, b));
  }
};
