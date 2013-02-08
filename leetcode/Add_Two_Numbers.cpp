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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode *prev = NULL;
        int inc = 0;
        while (l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + inc;
            inc = sum / 10;
            if (head == NULL) {
                prev = head = new ListNode(sum % 10);
            } else {
                prev->next = new ListNode(sum % 10);
                prev = prev->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            int sum = l1->val + inc;
            inc = sum / 10;
            prev->next = new ListNode(sum % 10);
            prev = prev->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int sum = l2->val + inc;
            inc = sum / 10;
            prev->next = new ListNode(sum % 10);
            prev = prev->next;
            l2 = l2->next;
        }
        if (inc > 0)
            prev->next = new ListNode(inc);
        return head;
    }
};
