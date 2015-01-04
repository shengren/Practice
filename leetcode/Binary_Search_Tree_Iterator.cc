/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
 public:
  BSTIterator(TreeNode *root) {
    PushLefts(root);
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !stack_.empty();
  }

  /** @return the next smallest number */
  int next() {
    pair<TreeNode *, bool> c = stack_.top();
    stack_.pop();
    if (c.second) {
      stack_.push(make_pair(c.first, false));
      PushLefts(c.first->right);
    }
    while (!stack_.empty() && !stack_.top().second) {
      stack_.pop();
    }
    return c.first->val;
  }

 private:
  void PushLefts(TreeNode *node) {
    while (node != nullptr) {
      stack_.push(make_pair(node, true));
      node = node->left;
    }
  }

  stack<pair<TreeNode *, bool>> stack_;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */