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
    vector<vector<int> > paths;
    void findPath(TreeNode *node, int current_sum, vector<int> &path) {
        if (node == NULL)
            return;
        current_sum += node->val;
        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL &&
            current_sum == target_sum) {
            paths.push_back(path);
            path.pop_back();
            return;
        }
        findPath(node->left, current_sum, path);
        findPath(node->right, current_sum, path);
        path.pop_back();
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        target_sum = sum;
        paths.clear();
        vector<int> path;
        findPath(root, 0, path);
        return paths;
    }
};
