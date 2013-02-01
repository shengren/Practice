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
    TreeNode *build(vector<int> &preorder, int begin_pre, int end_pre,
                    vector<int> &inorder,  int begin_in,  int end_in) {
        // Assume the input is valid.
        if (begin_pre >= end_pre)
            return NULL;
        vector<int>::iterator iter_mid = find(inorder.begin(),
                                              inorder.end(),
                                              preorder[begin_pre]);
        int mid = iter_mid - inorder.begin();
        TreeNode *node = new TreeNode(inorder[mid]);
        node->left  = 
            build(preorder, begin_pre + 1, begin_pre + 1 + (mid - begin_in),
                  inorder,  begin_in,      mid);
        node->right = 
            build(preorder, begin_pre + 1 + (mid - begin_in), end_pre,
                  inorder,  mid + 1,                          end_in);
        return node;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, 0, preorder.size(),
                     inorder,  0, inorder.size());
    }
};
