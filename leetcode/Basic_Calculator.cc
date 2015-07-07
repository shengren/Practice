class Solution {
 public:
  int calculate(string s) {
    stack<int> nu;
    stack<char> op;
    int curr_nu = 0;
    char curr_op = '?';
    int p = 0;

    while (p < s.size()) {
      if (s[p] == ' ') {
        ++p;
      } else if (s[p] == '+' || s[p] == '-') {
        curr_op = s[p];
        ++p;
      } else if (s[p] == '(') {
        nu.push(curr_nu);
        curr_nu = 0;
        op.push(curr_op);
        curr_op = '?';
        ++p;
      } else if (s[p] == ')') {
        int next_nu = curr_nu;
        curr_nu = nu.top();
        nu.pop();
        curr_op = op.top();
        op.pop();
        Operate(curr_nu, curr_op, next_nu);
        ++p;
      } else {  // operand
        int next_nu = GetNumber(s, p);
        Operate(curr_nu, curr_op, next_nu);
      }
    }

    return curr_nu;
  }

 private:
  int GetNumber(const string &s, int &p) {
    int nu = 0;
    while (p < s.size() && s[p] >= '0' && s[p] <= '9') {
      nu = nu * 10 + s[p] - '0';
      ++p;
    }
    return nu;
  }

  void Operate(int &curr_nu, char &curr_op, int next_nu) {
    if (curr_op == '+') {
      curr_nu += next_nu;
      curr_op = '?';
    } else if (curr_op == '-') {
      curr_nu -= next_nu;
      curr_op = '?';
    } else {  // curr_op == '?'
      curr_nu = next_nu;
    }
  }
};
