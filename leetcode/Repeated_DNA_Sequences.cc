inline int Convert(char c) {
  if (c == 'A') return 0;
  else if (c == 'C') return 1;
  else if (c == 'G') return 2;
  else if (c == 'T') return 3;
  else return -1;
}

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ret;
    if (s.size() < 10) return ret;
    unordered_map<int, int> ht;
    int p = 0;
    for (int i = 0; i < 9; ++i) {
      p = p << 2 | Convert(s[i]);
    }
    for (int i = 9; i < s.size(); ++i) {
      p = p << 2 & 0xFFFFF | Convert(s[i]);
      if (++ht[p] == 2) {
        ret.push_back(s.substr(i - 9, 10));
      }
    }
    return ret;
  }
};