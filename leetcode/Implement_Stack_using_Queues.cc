class Stack {
 public:
  // Push element x onto stack.
  void push(int x) {
    q.push(x);
  }

  // Removes the element on top of the stack.
  void pop() {
    int n = q.size() - 1;
    while (n--) {
      q.push(q.front());
      q.pop();
    }
    q.pop();
  }

  // Get the top element.
  int top() {
    int n = q.size();
    int ret;
    while (n--) {
      ret = q.front();
      q.push(ret);
      q.pop();
    }
    return ret;
  }

  // Return whether the stack is empty.
  bool empty() {
    return q.empty();
  }

 private:
  queue<int> q;
};
