class Solution {
 public:
  int compareVersion(string version1, string version2) {
    vector<string> num_seq1 = Split(version1);
    vector<string> num_seq2 = Split(version2);
    while (num_seq1.size() < num_seq2.size()) num_seq1.push_back("0");
    while (num_seq1.size() > num_seq2.size()) num_seq2.push_back("0");

    int a = 0;
    int b = 0;
    while (a < num_seq1.size()) {
      int r = Compare(num_seq1[a], num_seq2[b]);
      if (r != 0) return r;
      a++;
      b++;
    }

    return 0;
  }

 private:
  vector<string> Split(const string &v) {
    vector<string> ret;
    string num = "";
    for (int i = 0; i <= v.size(); ++i) {
      if (i == v.size() || v[i] == '.') {
        ret.push_back(num);
        num = "";
      } else {
        num += v[i];
      }
    }
    return ret;
  }
  
  int Compare(const string &x, const string &y) {
    int nx = atoi(x.c_str());
    int ny = atoi(y.c_str());
    if (nx < ny) return -1;
    if (nx > ny) return 1;
    return 0;
  }
};