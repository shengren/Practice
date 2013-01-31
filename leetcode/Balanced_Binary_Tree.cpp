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
    bool isBalancedTree;
    int findDepth(TreeNode *node) {
        if (node == NULL)
            return 0;
        int left_depth = findDepth(node->left);
        if (!isBalancedTree)
            return -1;
        int right_depth = findDepth(node->right);
        if (!isBalancedTree)
            return -1;
        if (abs(left_depth - right_depth) > 1) {
            isBalancedTree = false;
            return -1;
        }
        // remember to add 1
        return 1 + ((left_depth > right_depth) ? left_depth : right_depth);
    }
public:
    bool isBalanced(TreeNode *root) {
        isBalancedTree = true;
        findDepth(root);
        return isBalancedTree;
    }
};
