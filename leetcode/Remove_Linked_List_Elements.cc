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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *new_head = nullptr;
    ListNode *last = nullptr;
    ListNode *cur = head;

    while (cur != nullptr) {
      if (cur->val != val) {
        if (last == nullptr) {
          new_head = last = cur;
        } else {
          last->next = cur;
          last = last->next;
        }
      }
      cur = cur->next;
    }

    if (last != nullptr) last->next = nullptr;

    return new_head;
  }
};
