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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;

    ListNode *nodeA = headA;
    int lenA = 1;
    while (nodeA->next != nullptr) {
      nodeA = nodeA->next;
      lenA++;
    }

    ListNode *nodeB = headB;
    int lenB = 1;
    while (nodeB->next != nullptr) {
      nodeB = nodeB->next;
      lenB++;
    }

    if (nodeA != nodeB) return nullptr;

    nodeA = headA;
    nodeB = headB;
    while (lenA > lenB) {
      nodeA = nodeA->next;
      lenA--;
    }
    while (lenA < lenB) {
      nodeB = nodeB->next;
      lenB--;
    }
    
    while (nodeA != nodeB) {
      nodeA = nodeA->next;
      nodeB = nodeB->next;
    }
    return nodeA;
  }
};