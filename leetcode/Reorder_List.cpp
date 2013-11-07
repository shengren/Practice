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
    void reorderList(ListNode *head) {
      if (!head)
        return;

      stack<ListNode *> s;
      ListNode *p = head;
      while (p) {
        s.push(p);
        p = p->next;
      }

      int len = s.size();
      ListNode *prev = NULL;
      ListNode *curr = head;
      ListNode *next = curr->next;
      for (int i = 0; i < len / 2; ++i) {
        curr->next = s.top();
        s.pop();
        curr->next->next = next;
        prev = curr->next;
        curr = next;
        next = next->next;
      }
      if (len % 2)
        curr->next = NULL;
      else
        prev->next = NULL;
    }
};
