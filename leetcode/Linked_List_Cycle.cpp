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
    bool hasCycle(ListNode *head) {
      ListNode *cursor1 = head;
      ListNode *cursor2 = head;
      bool start = true;
      while (cursor2 != NULL) {
        if (start) {
          start = false;
        } else {
          if (cursor1 == cursor2)
            return true;
        }
        cursor1 = cursor1->next;
        if (cursor2->next != NULL)
          cursor2 = cursor2->next->next;
        else
          cursor2 = NULL;
      }
      return false;
    }
};
