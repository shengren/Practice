class Solution {
 public:
  int calculate(string s) {
    queue<char> pm;  // +, -
    queue<int> nu;  // For plus or minus
    int x, y;
    char op = '?';

    int k = 0;
    while (k < s.size()) {
      if (s[k] == ' ') {
        ++k;
      } else if (s[k] == '+' || s[k] == '-') {
        nu.push(x);
        pm.push(s[k]);
        ++k;
      } else if (s[k] == '*' || s[k] == '/') {
        op = s[k];
        ++k;
      } else {
        y = ReadNumber(s, k);
        if (op != '?') {
          if (op == '*')
            x *= y;
          else
            x /= y;
          op = '?';
        } else {
          x = y;
        }
      }
    }
    nu.push(x);

    x = nu.front();
    nu.pop();
    while (!pm.empty()) {
      op = pm.front();
      pm.pop();
      y = nu.front();
      nu.pop();
      if (op == '+')
        x += y;
      else
        x -= y;
    }

    return x;
  }

 private:
  int ReadNumber(const string &s, int &k) {
    int ret = 0;
    while (k < s.size() && s[k] >= '0' && s[k] <= '9') {
      ret = ret * 10 + s[k] - '0';
      ++k;
    }
    return ret;
  }
};
