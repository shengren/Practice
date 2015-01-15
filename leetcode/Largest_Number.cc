bool cmp(const string &a, const string &b) {
  return a + b >= b + a;
}

class Solution {
 public:
  string largestNumber(vector<int> &num) {
    string zeros = "";
    vector<string> str;
    for (int x : num) {
      if (x == 0)
        zeros += '0';
      else
        str.push_back(to_string(x));
    }

    if (str.empty()) return "0";  // all zeros

    sort(str.begin(), str.end(), cmp);
    string ret = "";
    for (string s : str) ret += s;

    return ret + zeros;
  }
};
