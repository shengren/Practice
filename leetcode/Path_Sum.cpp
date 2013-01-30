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
    int target_sum;
    bool findPath(TreeNode *node, int current_sum) {
        if (node == NULL)
            return false;
        current_sum += node->val;
        if (node->left == NULL && node->right == NULL &&  // It must be a leaf
            current_sum == target_sum)
            return true;
        //if (current_sum > target_sum)  // Wrong pruning. Values might be negative.
        //    return false;
        if (findPath(node->left, current_sum))
            return true;
        return findPath(node->right, current_sum);
    }
public:
    bool hasPathSum(TreeNode *root, int sum) {
        target_sum = sum;
        return findPath(root, 0);
    }
};
