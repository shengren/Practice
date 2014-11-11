class MinStack {
 public:
  void push(int x) {
    if (min_.empty() || min_.top().first > x)
      min_.push(make_pair(x, s_.size()));
    s_.push(x);
  }

  void pop() {
    s_.pop();
    if (min_.top().second == s_.size()) min_.pop();
  }

  int top() {
    return s_.top();
  }

  int getMin() {
    return min_.top().first;
  }

 private:
  stack<int> s_;
  stack<pair<int, int>> min_;
};
