#include <queue>
using namespace std;
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        queue<TreeLinkNode*> q;  // BFS
        queue<int> d;  // depth of the cooresponding node
        q.push(root);
        d.push(1);  // root is on level 1
        TreeLinkNode *pre = NULL;
        int pre_d;  // depth of the node 'pre'
        while (!q.empty()) {
            TreeLinkNode *cur = q.front();
            q.pop();
            int cur_d = d.front();
            d.pop();
            if (pre != NULL && pre_d == cur_d) {
                // ->next is initialized as NULL
                pre->next = cur;
            }
            pre = cur;
            pre_d = cur_d;
            if (cur->left != NULL) {
                q.push(cur->left);
                d.push(cur_d + 1);
            }
            if (cur->right != NULL) {
                q.push(cur->right);
                d.push(cur_d + 1);
            }
        }
    }
};
