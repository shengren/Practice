class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> num;
    for (int i = 0; i < tokens.size(); ++i) {
      if (tokens[i] == "+") {
        int b = num.top();
        num.pop();
        int a = num.top();
        num.pop();
        num.push(a + b);
      } else if (tokens[i] == "-") {
        int b = num.top();
        num.pop();
        int a = num.top();
        num.pop();
        num.push(a - b);
      } else if (tokens[i] == "*") {
        int b = num.top();
        num.pop();
        int a = num.top();
        num.pop();
        num.push(a * b);
      } else if (tokens[i] == "/") {
        int b = num.top();
        num.pop();
        int a = num.top();
        num.pop();
        num.push(a / b);
      } else {
        num.push(str2int(tokens[i]));
      }
    }
    return num.top();
   }

 private:
  int str2int(string s) {
    istringstream iss(s);
    int x;
    iss >> x;
    return x;
  }
};
