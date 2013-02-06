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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *prev_node = NULL;
        ListNode *next_node = NULL;
        ListNode *curr_node = head;
        stack<ListNode *> cache;
        while (curr_node != NULL) {
            cache.push(curr_node);
            next_node = curr_node->next;
            if (cache.size() == k) {
                if (prev_node == NULL)
                    head = curr_node;
                while (!cache.empty()) {
                    curr_node = cache.top();
                    cache.pop();
                    if (prev_node != NULL) {
                        prev_node->next = curr_node;
                    }
                    prev_node = curr_node;
                }
                curr_node->next = next_node;
            }
            curr_node = next_node;
        }
        return head;
    }
};
