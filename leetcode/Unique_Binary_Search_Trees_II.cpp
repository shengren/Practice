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
    vector<TreeNode *> generate(int a, int b) {  // [a, b]
        vector<TreeNode *> trees;
        if (a > b) {
            trees.push_back(NULL);
            return trees;
        }

        for (int m = a; m <= b; ++m) {
            vector<TreeNode *> left_subtrees = generate(a, m - 1);
            vector<TreeNode *> right_subtrees = generate(m + 1, b);                
            for (int i = 0; i < left_subtrees.size(); ++i)
                for (int j = 0; j < right_subtrees.size(); ++j) {
                    TreeNode *new_tree = new TreeNode(m);
                    // Subtrees are reused
                    new_tree->left = left_subtrees[i];
                    new_tree->right = right_subtrees[j];
                    trees.push_back(new_tree);
                }
        }
        return trees;
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        // When n = 0, return a pointer with NULL
        return generate(1, n);
    }
};
