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
    int max_depth;
    void findMaxDepth(TreeNode *node, int depth) {
        if (node == NULL)
            return;
        if (max_depth < depth)
            max_depth = depth;
        findMaxDepth(node->left, depth + 1);
        findMaxDepth(node->right, depth + 1);
    }
public:
    int maxDepth(TreeNode *root) {
        max_depth = 0;
        findMaxDepth(root, 1);
        return max_depth;
    }
};
