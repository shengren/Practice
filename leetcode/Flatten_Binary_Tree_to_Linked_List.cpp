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
    TreeNode *last;
    void doFlatten(TreeNode *node) {
        if (node == NULL)
            return;
        last = node;
        doFlatten(node->left);
        if (node->left != NULL) {
            last->right = node->right;
            node->right = node->left;
            node->left = NULL;  // forgot to reset this at first
        }
        doFlatten(last->right);
    }
public:
    void flatten(TreeNode *root) {
        doFlatten(root);
    }
};
