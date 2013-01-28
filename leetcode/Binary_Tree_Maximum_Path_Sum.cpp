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
  int max_path_sum;

  int searchPath(TreeNode *current) {
    int extensible_path = current->val;

    int extensible_path_from_left;
    if (current->left != NULL) {
      extensible_path_from_left = searchPath(current->left);
      if (extensible_path < current->val + extensible_path_from_left)
        extensible_path = current->val + extensible_path_from_left;
    }

    int extensible_path_from_right;
    if (current->right != NULL) {
      extensible_path_from_right = searchPath(current->right);
      if (extensible_path < current->val + extensible_path_from_right)
        extensible_path = current->val + extensible_path_from_right;
    }

    if (max_path_sum < extensible_path)
      max_path_sum = extensible_path;

    if (current->left != NULL && current->right != NULL) {
      if (max_path_sum < current->val +
                         extensible_path_from_left +
                         extensible_path_from_right) {
        max_path_sum = current->val +
                       extensible_path_from_left +
                       extensible_path_from_right;
      }
    }

    return extensible_path;
  }

 public:
  int maxPathSum(TreeNode *root) {
    if (root == NULL)
      return 0;
    max_path_sum = root->val;
    // max_path_sum is updated within the function.
    // The return value is the max sum of the extensible path that starts from
    // the node 'current'.
    searchPath(root);
    return max_path_sum;
  }
};
