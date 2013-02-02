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
    TreeNode *rightmost_smaller_than_left;
    TreeNode *leftmost_larger_than_right;
    void findRightmostSmallerThanLeft(TreeNode *node, int &max_on_left) {
        if (node == NULL)
            return;
        findRightmostSmallerThanLeft(node->left, max_on_left);
        if (max_on_left > node->val) {
            if (rightmost_smaller_than_left == NULL ||
                rightmost_smaller_than_left->val > node->val)
                rightmost_smaller_than_left = node;
        } else {
            max_on_left = node->val;
        }
        findRightmostSmallerThanLeft(node->right, max_on_left);
    }
    void findLeftmostLargerThanRight(TreeNode *node, int &min_on_right) {
        if (node == NULL)
            return;
        findLeftmostLargerThanRight(node->right, min_on_right);
        if (min_on_right < node->val) {
            if (leftmost_larger_than_right == NULL ||
                leftmost_larger_than_right->val < node->val)
                leftmost_larger_than_right = node;
        } else {
            min_on_right = node->val;
        }
        findLeftmostLargerThanRight(node->left, min_on_right);
    }
public:
    void recoverTree(TreeNode *root) {
        rightmost_smaller_than_left = leftmost_larger_than_right = NULL;
        int max_on_left = -987654321;
        findRightmostSmallerThanLeft(root, max_on_left);
        int min_on_right = 987654321;
        findLeftmostLargerThanRight(root, min_on_right);
        
        int tmp = rightmost_smaller_than_left->val;
        rightmost_smaller_than_left->val = leftmost_larger_than_right->val;
        leftmost_larger_than_right->val = tmp;
    }
};
