/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    int findLength(ListNode *node) {
        int len = 0;
        while (node != NULL) {
            ++len;
            node = node->next;
        }
        return len;
    }
    TreeNode *buildBST(ListNode *node, int len) {
        if (len == 0)
            return NULL;
            
        int mid = 1 + len / 2;
        int idx = 1;
        ListNode *mid_node = node;
        while (idx < mid) {
            mid_node = mid_node->next;
            ++idx;
        }
        
        TreeNode *tree_node = new TreeNode(mid_node->val);
        tree_node->left = buildBST(node, mid - 1);
        tree_node->right = buildBST(mid_node->next, len - mid);
        return tree_node;
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return buildBST(head, findLength(head));
    }
};
