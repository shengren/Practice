/**
 *  * Definition for binary tree
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */

typedef pair<TreeNode *, bool> PNB;  // boolean: if it's been explored.

class Solution {
  stack<PNB> waiting;
  public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ret;
    if (root)
      waiting.push(make_pair(root, false));
    while (!waiting.empty()) {
      PNB pnb = waiting.top();
      waiting.pop();
      if (pnb.second) {
        ret.push_back((pnb.first)->val);
      } else {
        waiting.push(make_pair(pnb.first, true));
        if ((pnb.first)->right)
          waiting.push(make_pair((pnb.first)->right, false));
        if ((pnb.first)->left)
          waiting.push(make_pair((pnb.first)->left, false));
      }
    }
    return ret;
  }
};
