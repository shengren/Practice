class Solution {
 public:
  int titleToNumber(string s) {
    int ret = 0;
    for (char c : s) {
      int x = c - 'A' + 1;
      ret = ret * 26 + x;
    }
    return ret;
  }
};