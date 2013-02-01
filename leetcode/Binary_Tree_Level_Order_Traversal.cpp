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
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > traversal;
        if (root == NULL)
            return traversal;

        queue<TreeNode*> node_queue;
        node_queue.push(root);
        queue<int> depth_queue;
        depth_queue.push(0);  // 0-based
        int pre_depth = -1;
        while (!node_queue.empty()) {
            TreeNode *node = node_queue.front();
            node_queue.pop();
            int depth = depth_queue.front();
            depth_queue.pop();
            if (pre_depth < depth) {
                // the way to add an empty vector
                traversal.push_back(vector<int>());
                pre_depth = depth;
            }
            traversal[depth].push_back(node->val);
            if (node->left != NULL) {
                node_queue.push(node->left);
                depth_queue.push(depth + 1);
            }
            if (node->right != NULL) {
                node_queue.push(node->right);
                depth_queue.push(depth + 1);
            }
        }
        return traversal;
    }
};
