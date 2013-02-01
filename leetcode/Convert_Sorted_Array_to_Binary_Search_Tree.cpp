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
    TreeNode *buildBST(vector<int> &num, int begin, int end) {
        if (begin == end)
            return NULL;
        int mid = (begin + end) / 2;
        TreeNode *tree_node = new TreeNode(num[mid]);
        tree_node->left = buildBST(num, begin, mid);
        tree_node->right = buildBST(num, mid + 1, end);
        return tree_node;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return buildBST(num, 0, num.size());
    }
};
