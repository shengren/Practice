/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *node = head;
        int pos = 0;
        int mid = (m + n) / 2;
        stack<ListNode *> swapping;
        while (node != NULL) {
            ++pos;
            if (pos >= m && pos <= n) {
                if (pos <= mid) {
                    swapping.push(node);
                }
                // Mind the condition for segment having odd items
                if (pos > mid || (pos == mid && mid - m == n - mid)) {
                    ListNode *paired_node = swapping.top();
                    swapping.pop();
                    int tmp = node->val;
                    node->val = paired_node->val;
                    paired_node->val = tmp;
                }
            }
            node = node->next;
        }
        return head;
    }
};
