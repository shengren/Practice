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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > traversal;
        if (root == NULL)
            return traversal;
        
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        queue<int> depth_queue;  // 0-based
        depth_queue.push(0);
        int pre_depth = -1;
        while (!node_queue.empty()) {
            TreeNode *node = node_queue.front();
            node_queue.pop();
            int depth = depth_queue.front();
            depth_queue.pop();
            if (pre_depth < depth) {
                if (pre_depth > 0 && pre_depth % 2 == 1)
                    reverse(traversal[pre_depth].begin(),
                            traversal[pre_depth].end());
                pre_depth = depth;
                traversal.push_back(vector<int>());
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
        // Remember to reverse the last row if needed. Forgot at first.
        if (traversal.size() % 2 == 0)
            reverse(traversal[traversal.size() - 1].begin(),
                    traversal[traversal.size() - 1].end());
        return traversal;
    }
};
