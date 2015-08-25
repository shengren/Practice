/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ret;
    
    if (root == nullptr) return ret;
    
    Traverse(root, "", ret);
    return ret;
  }

 private:
  void Traverse(TreeNode *node, string prefix, vector<string> &paths) {
    Append(prefix, node);

    if (node->left == nullptr && node->right == nullptr) {
      paths.push_back(prefix);
      return;
    }

    if (node->left != nullptr) Traverse(node->left, prefix, paths);
    if (node->right != nullptr) Traverse(node->right, prefix, paths);
  }

  void Append(string &prefix, TreeNode *node) {
    stringstream ss;
    if (!prefix.empty()) ss << "->";
    ss << node->val;
    prefix += ss.str();
  }
};
