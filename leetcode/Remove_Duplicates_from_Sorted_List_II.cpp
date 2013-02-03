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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        head = NULL;
        while (cur != NULL) {
            if (cur->next == NULL || cur->val != cur->next->val) {
                // Keep the current node.
                if (head == NULL)
                    head = cur;
                if (pre != NULL)
                    pre->next = cur;
                pre = cur;
                cur = cur->next;
                pre->next = NULL;
            } else {
                // Current value is duplicated. Skip them.
                int dup_val = cur->val;
                while (cur != NULL && cur->val == dup_val) {
                    ListNode *deleting = cur;
                    cur = cur->next;
                    delete deleting;
                }
            }
        }
        return head;
    }
};
