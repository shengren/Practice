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
    void pushLeftSubtree(TreeNode *node, stack<TreeNode*> &printing) {
        while (node != NULL) {
            printing.push(node);
            node = node->left;
        }
    }
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> inorder;
        stack<TreeNode*> printing;
        pushLeftSubtree(root, printing);
        while (!printing.empty()) {
            TreeNode *node = printing.top();
            printing.pop();
            inorder.push_back(node->val);
            pushLeftSubtree(node->right, printing);
        }
        return inorder;
    }
};
