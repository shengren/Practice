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
  bool isPalindrome(ListNode* head) {
    int len = GetLength(head);

    if (len <= 1) return true;

    // Reverse the second half
    ListNode *tail = Reverse(Forward(head, (len + 1) / 2), len / 2 - 1);

    bool ret = true;
    ListNode *nf = head;
    ListNode *nb = tail;
    for (int i = 0; i < len / 2; ++i) {
      if (nf->val != nb->val) {
        ret = false;
        break;
      }
      nf = nf->next;
      nb = nb->next;
    }

    // TLE if the input is not restored
    Reverse(tail, len / 2 - 1);
    tail->next = nullptr;

    return ret;
  }

 private:
  int GetLength(ListNode *node) {
    int ret = 0;
    while (node != nullptr) {
      ++ret;
      node = node->next;
    }
    return ret;
  }

  ListNode *Forward(ListNode *node, int n) {
    while (n--) node = node->next;
    return node;
  }

  ListNode *Reverse(ListNode *node, int n) {
    ListNode *next_node = node->next;
    while (n--) {
      ListNode *next_next_node = next_node->next;
      next_node->next = node;
      node = next_node;
      next_node = next_next_node;
    }
    return node;
  }
};
