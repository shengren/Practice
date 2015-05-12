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
  ListNode* reverseList(ListNode* head) {
    // return Iteratively(head);

    newhead = nullptr;
    Recursively(head);
    return newhead;
  }

 private:
  ListNode *Iteratively(ListNode *head) {
    ListNode *cur = head;
    head = nullptr;
    while (cur != nullptr) {
      ListNode *next = cur->next;
      cur->next = head;
      head = cur;
      cur = next;
    }
    return head;
  }

  ListNode *Recursively(ListNode *head) {
    if (head == nullptr) return nullptr;
    newhead = head;
    ListNode *last = Recursively(head->next);
    if (last != nullptr) last->next = head;
    head->next = nullptr;
    return head;
  }

  ListNode *newhead;
};
