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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        stack<ListNode *> reverse_order;
        ListNode *cur = head;
        while (cur != NULL) {
            reverse_order.push(cur);
            cur = cur->next;
        }
        int reverse_index = 1;
        while (reverse_index < n) {
            reverse_order.pop();
            ++reverse_index;
        }
        ListNode *deleting = reverse_order.top();
        reverse_order.pop();
        if (!reverse_order.empty()) {
            ListNode *pre = reverse_order.top();
            reverse_order.pop();
            pre->next = deleting->next;
        } else {
            head = deleting->next;
        }
        delete deleting;
        return head;
    }
};
