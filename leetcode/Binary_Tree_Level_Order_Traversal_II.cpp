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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        max_depth = 0;
        findMaxDepth(root, 1);
        
        vector<vector<int> > traversal(max_depth);
        if (root == NULL)
            return traversal;
            
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        queue<int> idx_queue;
        idx_queue.push(max_depth - 1);
        while (!node_queue.empty()) {
            TreeNode *node = node_queue.front();
            node_queue.pop();
            int idx = idx_queue.front();
            idx_queue.pop();
            traversal[idx].push_back(node->val);
            if (node->left != NULL) {
                node_queue.push(node->left);
                idx_queue.push(idx - 1);
            }
            if (node->right != NULL) {
                node_queue.push(node->right);
                idx_queue.push(idx - 1);
            }
        }
        return traversal;
    }
};
