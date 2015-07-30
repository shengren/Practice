class Solution {
 public:
  vector<int> diffWaysToCompute(string input) {
    Parse(input, nu, op);
    return Find(0, op.size());
  }

 private:
  void Parse(const string &input, vector<int> &nu, vector<char> &op) {
    int n = 0;
    for (int i = 0; i < input.size(); ++i)
      if (input[i] >= '0' && input[i] <= '9') {
        n = n * 10 + input[i] - '0';
      } else {
        nu.push_back(n);
        n = 0;
        op.push_back(input[i]);
      }
    nu.push_back(n);
  }

  vector<int> Find(int a, int b) {
    if (a == b) {
      return {nu[a]};
    }
    vector<int> ret;
    for (int k = a; k < b; ++k) {
      vector<int> l = Find(a, k);
      vector<int> r = Find(k + 1, b);
      for (int i = 0; i < l.size(); ++i)
        for (int j = 0; j < r.size(); ++j)
          if (op[k] == '+')
            ret.push_back(l[i] + r[j]);
          else if (op[k] == '-')
            ret.push_back(l[i] - r[j]);
          else
            ret.push_back(l[i] * r[j]);
    }
    return ret;
  }

  vector<int> nu;
  vector<char> op;
};
