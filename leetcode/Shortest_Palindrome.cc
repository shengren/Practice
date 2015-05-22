class Solution {
 public:
  string shortestPalindrome(string s) {
    if (s == "") return "";

    vector<char> ch;
    vector<int> ct;
    
    for (int i = 0; i < s.size(); ++i)
      if (i == 0 || ch.back() != s[i]) {
        ch.push_back(s[i]);
        ct.push_back(1);
      } else {
        ++ct.back();
      }

    int m = (ch.size() - 1) / 2;
    while (!IsValid(m, ch, ct)) --m;
    
    return FillFront(m, ch, ct) + s;
  }

 private:
  bool IsValid(int m, const vector<char> &ch, const vector<int> &ct) {
    if (m == 0) return true;

    int d = 1;
    while (true) {
      int p = m - d;
      int q = m + d;

      if (ch[p] != ch[q]) return false;

      if (p == 0) {
        if (ct[p] <= ct[q])
          return true;
        else
          return false;
      } else {
        if (ct[p] != ct[q])
          return false;
      }

      ++d;
    }
  }

  string FillFront(int m, const vector<char> &ch, const vector<int> &ct) {
    string ret;
    int q = m + m;

    for (int i = ch.size() - 1; i > q; --i)
      ret += string(ct[i], ch[i]);

    if (ct[q] > ct[0])
      ret += string(ct[q] - ct[0], ch[q]);

    return ret;
  }
};
