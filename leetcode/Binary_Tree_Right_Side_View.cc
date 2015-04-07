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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ret;
    vector<TreeNode *> level[2];

    if (root != nullptr)
      level[0].push_back(root);

    int p = 0;
    while (!level[p].empty()) {
      ret.push_back(level[p].back()->val);

      int q = 1 - p;
      level[q].clear();
      for (auto node : level[p]) {
        if (node->left != nullptr)
          level[q].push_back(node->left);
        if (node->right != nullptr)
          level[q].push_back(node->right);
      }

      p = 1 - p;
    }

    return ret;
  }
};
