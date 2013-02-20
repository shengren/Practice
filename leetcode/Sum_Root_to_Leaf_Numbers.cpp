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
    int sum;
    void extend(TreeNode *node, int pre) {
        int val = pre * 10 + node->val;
        if (node->left == NULL && node->right == NULL) {
            sum += val;
            return;
        }
        if (node->left != NULL)
            extend(node->left, val);
        if (node->right != NULL)
            extend(node->right, val);
    }
public:
    int sumNumbers(TreeNode *root) {
        if (root == NULL)
            return 0;
        sum = 0;
        extend(root, 0);
        return sum;
    }
};
