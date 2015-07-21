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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode *> path_p, path_q;
    DFS(root, p, path_p);
    DFS(root, q, path_q);
    int k = 0;
    while (k < path_p.size() && k < path_q.size() && path_p[k] == path_q[k])
      ++k;
    return path_p[k - 1];
  }

 private:
  void DFS(TreeNode *root, TreeNode *x, vector<TreeNode *> &path) {
    if (root == nullptr) return;

    path.push_back(root);

    if (root == x) return;
    
    DFS(root->left, x, path);
    if (path.back() == x) return;

    DFS(root->right, x, path);
    if (path.back() == x) return;

    path.pop_back();
  }
};
