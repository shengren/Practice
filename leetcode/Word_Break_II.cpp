class Solution {
  public:
    vector<string> found;
    void dfs(int pos, string sol, const string s, const vector<vector<int> > &b) {
      if (pos == 0) {
        found.push_back(sol);
        return;
      }
      for (int i = 0; i < b[pos].size(); ++i) {
        string w = s.substr(b[pos][i] + 1, pos - b[pos][i]);
        if (sol != "")
          w += " ";
        dfs(b[pos][i], w + sol, s, b);
      }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
      s = "#" + s;
      vector<vector<int> > backwards(s.size(), vector<int>());
      backwards[0].push_back(-1);
      for (int i = 0; i < s.size() - 1; ++i)
        if (backwards[i].size() != 0) {
          int j = 1;
          while (i + j < s.size()) {
            string w = s.substr(i + 1, j);
            if (dict.find(w) != dict.end())
              backwards[i + j].push_back(i);
            ++j;
          }
        }
      found.clear();
      dfs(s.size() - 1, "", s, backwards);
      return found;
    }
};
