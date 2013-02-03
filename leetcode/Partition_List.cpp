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
    ListNode *partition(ListNode *head, int x) {
        ListNode *small_list_head = NULL;
        ListNode *small_list_tail = NULL;
        ListNode *large_list_head = NULL;
        ListNode *large_list_tail = NULL;
        ListNode *current = head;
        while (current != NULL) {
            if (current->val < x) {
                if (small_list_head == NULL) {
                    small_list_head = small_list_tail = current;
                } else {
                    small_list_tail->next = current;
                    small_list_tail = current;
                }
            } else {
                if (large_list_head == NULL) {
                    large_list_head = large_list_tail = current;
                } else {
                    large_list_tail->next = current;
                    large_list_tail = current;
                }
            }
            current = current->next;
        }
        if (small_list_head == NULL) {
            return large_list_head;
        } else {
            small_list_tail->next = large_list_head;
            if (large_list_tail != NULL)  // large_list might be empty
                large_list_tail->next = NULL;
            return small_list_head;
        }
    }
};
