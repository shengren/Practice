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
    bool check(TreeNode *node, int lower_bound, int upper_bound) {
        if (node == NULL)
            return true;
        // strictly less or greater than
        if (node->val <= lower_bound || node->val >= upper_bound)
            return false;
        if (!check(node->left,  lower_bound, node->val) ||
            !check(node->right, node->val,   upper_bound))
            return false;
        return true;
    }
public:
    bool isValidBST(TreeNode *root) {
        return check(root, -987654321, 987654321);
    }
};
