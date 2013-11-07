/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
      vector<int> ret;
      stack<TreeNode *> waiting;
      if (root)
        waiting.push(root);
      while (!waiting.empty()) {
        TreeNode *node = waiting.top();
        waiting.pop();
        ret.push_back(node->val);
        if (node->right)
          waiting.push(node->right);
        if (node->left)
          waiting.push(node->left);
      }
      return ret;
    }
};
