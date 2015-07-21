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
  int kthSmallest(TreeNode* root, int k) {
    DFS(root, k);
    return res;
  }

 private:
  int DFS(TreeNode *root, int k) {
    if (root == nullptr) return 0;

    int nl = DFS(root->left, k);
    if (nl == -1) return -1;
    
    if (nl + 1 == k) {
      res = root->val;
      return -1;
    }
    
    int nr = DFS(root->right, k - nl - 1);
    if (nr == -1) return -1;
    
    return nl + 1 + nr;
  }

  int res;
};
