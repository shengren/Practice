/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int findLength(ListNode *node, ListNode **tail) {
        int length = 0;
        while (node != NULL) {
            *tail = node;
            length += 1;
            node = node->next;
        }
        return length;
    }
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL)
            return head;
        ListNode *tail;
        int length = findLength(head, &tail);
        k %= length;
        if (k == 0)
            return head;
        int idx = 1;
        ListNode *node = head;
        while (idx < length - k) {
            idx += 1;
            node = node->next;
        }
        tail->next = head;
        head = node->next;
        node->next = NULL;
        return head;
    }
};
