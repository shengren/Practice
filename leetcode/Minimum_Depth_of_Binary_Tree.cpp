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
    int minDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        queue<int> depth_queue;
        depth_queue.push(1);
        while (!node_queue.empty()) {
            TreeNode *node = node_queue.front();
            node_queue.pop();
            int depth = depth_queue.front();
            depth_queue.pop();
            if (node->left == NULL && node->right == NULL)
                return depth;
            if (node->left != NULL) {
                node_queue.push(node->left);
                depth_queue.push(depth + 1);
            }
            if (node->right != NULL) {
                node_queue.push(node->right);
                depth_queue.push(depth + 1);
            }
        }
    }
};
