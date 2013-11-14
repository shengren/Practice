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
    ListNode *insertionSortList(ListNode *head) {
      if (!head || !(head->next))
        return head;

      ListNode *tail = head;
      ListNode *wait = tail->next;
      tail->next = NULL;

      while (wait) {
        ListNode *curr = wait;
        wait = wait->next;
        if (curr->val <= head->val) {
          curr->next = head;
          head = curr;
        } else if (curr->val >= tail->val) {
          tail->next = curr;
          tail = curr;
          tail->next = NULL;
        } else {
          ListNode *p = head;
          while (p->next->val < curr->val)
            p = p->next;
          curr->next = p->next;
          p->next = curr;
        }
      }

      return head;
    }
};
