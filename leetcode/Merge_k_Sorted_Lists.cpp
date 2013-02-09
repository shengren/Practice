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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = NULL;
        ListNode *prev = NULL;
        while (true) {
            int idx = -1;
            int min_val = numeric_limits<int>::max();
            for (int i = 0; i < lists.size(); ++i)
                if (lists[i] != NULL && min_val > lists[i]->val) {
                    idx = i;
                    min_val = lists[i]->val;
                }
            if (idx == -1)
                break;
            if (head == NULL)
                head = lists[idx];
            else
                prev->next = lists[idx];
            prev = lists[idx];
            lists[idx] = lists[idx]->next;
        }
        return head;
    }
};
