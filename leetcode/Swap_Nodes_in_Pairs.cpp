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
    ListNode *swapPairs(ListNode *head) {
        ListNode *prev_node = NULL;
        ListNode *next_node = NULL;
        ListNode *swapping_node = NULL;
        ListNode *current_node = head;
        while (current_node != NULL) {
            next_node = current_node->next;
            if (swapping_node == NULL) {
                swapping_node = current_node;
            } else {
                if (prev_node == NULL)
                    head = current_node;
                if (prev_node != NULL)
                    prev_node->next = current_node;
                current_node->next = swapping_node;
                prev_node = swapping_node;  // Forgot this at first
                swapping_node->next = next_node;
                swapping_node = NULL;
            }
            current_node = next_node;
        }
        return head;
    }
};
