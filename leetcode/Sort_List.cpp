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
    ListNode *sortList(ListNode *head) {
      if (!head || !(head->next))
        return head;

      ListNode *p = head->next;
      int len = 1;
      while (p) {
        ++len;
        p = p->next;
      }

      int mid = 0;
      ListNode *pre = NULL;
      ListNode *q = head;
      while (mid < len / 2) {
        pre = q;
        q = q->next;
        ++mid;
      }
      pre->next = NULL;

      p = sortList(head);
      q = sortList(q);

      ListNode *ret = NULL;
      pre = NULL;
      while (p && q) {
        if (p->val < q->val) {
          if (!ret)
            ret = p;
          else
            pre->next = p;
          pre = p;
          p = p->next;
        } else {
          if (!ret)
            ret = q;
          else
            pre->next = q;
          pre = q;
          q = q->next;
        }
      }
      while (p) {
        if (!ret)
          ret = p;
        else
          pre->next = p;
        pre = p;
        p = p->next;
      }
      while (q) {
        if (!ret)
          ret = q;
        else
          pre->next = q;
        pre = q;
        q = q->next;
      }

      return ret;
    }
};
