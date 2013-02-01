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
    TreeNode *build(vector<int> &inorder,   int begin_in,   int end_in, 
                    vector<int> &postorder, int begin_post, int end_post) {
        // Assume the input is valid.
        if (begin_in >= end_in)
            return NULL;
        vector<int>::iterator iter_mid = find(inorder.begin() + begin_in,
                                              inorder.begin() + end_in,
                                              postorder[end_post - 1]);
        int mid = iter_mid - inorder.begin();
        TreeNode *node = new TreeNode(inorder[mid]);
        node->left  = build(
                        inorder,   begin_in,   mid,
                        postorder, begin_post, begin_post + (mid - begin_in));
        node->right = build(
                        inorder,   mid + 1,                       end_in,
                        postorder, begin_post + (mid - begin_in), end_post - 1);
        return node;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder,   0, inorder.size(),
                     postorder, 0, postorder.size());
    }
};
