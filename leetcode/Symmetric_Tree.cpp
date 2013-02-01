/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef pair<TreeNode*, TreeNode*> PNN;

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        stack<PNN> checking;
        checking.push(make_pair(root->left, root->right));
        while (!checking.empty()) {
            PNN current_pair = checking.top();
            checking.pop();
            TreeNode *x = current_pair.first;
            TreeNode *y = current_pair.second;
            if (x == NULL && y == NULL)
                continue;
            if ((x == NULL && y != NULL) ||
                (x != NULL && y == NULL))
                return false;
            if (x->val != y->val)
                return false;
            checking.push(make_pair(x->left,  y->right));
            checking.push(make_pair(x->right, y->left));
        }
        return true;
    }
};
