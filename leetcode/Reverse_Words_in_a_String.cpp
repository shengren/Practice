class Solution {
 public:
  void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    int i = 0;
    int j = 0;
    string ret = "";
    while (j <= s.size()) {
      if (j == s.size() || s[j] == ' ') {
        if (s[i] != ' ') {
          reverse(s.begin() + i, s.begin() + j);
          if (!ret.empty()) ret += ' ';
          ret += s.substr(i, j - i);
          i = j;
        }
      } else {
        if (s[i] == ' ') i = j;
      }
      j++;
    }
    s = ret;
  }
};
