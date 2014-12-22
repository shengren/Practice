class Solution {
 public:
  string convertToTitle(int n) {
    string title = "";
    while (n > 0) {
      title = char('A' + (n - 1) % 26) + title;
      n = (n - 1) / 26;
    }
    return title;
  }
};