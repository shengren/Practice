/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    int max_depth;
    TreeLinkNode *pre;
    void findMaxDepth(TreeLinkNode *node, int depth) {
        if (node == NULL)
            return;
        if (max_depth < depth)
            max_depth = depth;
        findMaxDepth(node->left, depth + 1);
        findMaxDepth(node->right, depth + 1);
    }
    void findNext(TreeLinkNode *node, int target_depth, int depth) {
        if (node == NULL)
            return;
        if (depth == target_depth) {
            if (pre == NULL) {
                pre = node;
            } else {
                pre->next = node;
                pre = node;
            }
            return;
        }
        findNext(node->left, target_depth, depth + 1);
        findNext(node->right, target_depth, depth + 1);
    }
public:
    // To satisfy the constant extra space requirement, we first find out the 
    // depth of the tree and then create the links level by level. Thus, beside
    // the space used for recursion, there is only one node pointer 'pre'.
    // This solution also works for 
    // <Populating Next Right Pointers in Each Node II>, for which we keeps the 
    // BFS version. BFS is faster but uses O(n) extra space, where n is the 
    // maximum number of nodes on one level.
    void connect(TreeLinkNode *root) {
        max_depth = 0;
        findMaxDepth(root, 1);
        for (int i = 1; i <= max_depth; ++i) {
            pre = NULL;
            findNext(root, i, 1);
        }
    }
};
