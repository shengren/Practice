class Solution {
  public:
    bool wordBreak(string s, unordered_set<string> &dict) {
      s = "#" + s;
      vector<bool> d(s.size(), false);
      d[0] = true;
      for (int i = 0; i < s.size() - 1; ++i)
        if (d[i]) {
          int j = 1;
          while (i + j < s.size()) {
            if (!d[i + j]) {
              string w = s.substr(i + 1, j);
              if (dict.find(w) != dict.end())
                d[i + j] = true;
            }
            j++;
          }
        }
      return d[d.size() - 1];
    }
};
