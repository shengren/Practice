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
  int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;

    max_depth = GetMaxDepth(root);

    if (Exist(root, (1 << max_depth) - 1)) return (1 << max_depth + 1) - 1;

    int lb = 1;
    int ub = 1 << max_depth;
    while (true) {
      int mid = (lb + ub) / 2;
      if (Exist(root, mid)) {
        lb = mid + 1;
      } else {
        if (Exist(root, mid - 1)) {
          return (1 << max_depth) - 1 + mid;
        } else {
          ub = mid;
        }
      }
    }
  }

 private:
  int GetMaxDepth(TreeNode *node) {  // root is on depth 0
    if (node->left == nullptr) return 0;
    return 1 + GetMaxDepth(node->left);
  }

  bool Exist(TreeNode *node, int leaf) {
    for (int i = max_depth - 1; i >= 0; --i)
      if ((leaf & 1 << i) == 0) {
        if (node->left == nullptr) return false;
        node = node->left;
      } else {
        if (node->right == nullptr) return false;
        node = node->right;
      }
    return true;
  }

  int max_depth;
};
