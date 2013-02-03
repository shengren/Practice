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
        // The input list is sorted.
        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur != NULL) {
            if (pre != NULL && pre->val == cur->val) {
                pre->next = cur->next;
                ListNode *deleting = cur;
                cur = cur->next;
                delete deleting;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
