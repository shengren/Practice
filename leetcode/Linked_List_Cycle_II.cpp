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
    ListNode *detectCycle(ListNode *head) {
      if (!head)
        return NULL;

      // Idetify if there is a cycle
      ListNode *cursor1 = head;
      ListNode *cursor2 = head;
      while (true) {
        cursor1 = cursor1->next;
        cursor2 = (cursor2->next) ? cursor2->next->next : NULL;
        if (!cursor1 || !cursor2)
          return NULL;  // No cycle
        if (cursor1 == cursor2)
          break;
      }

      ListNode *start = cursor1;

      // Calculate the length of the cycle
      int cycle_len = 0;
      while (true) {
        cursor1 = cursor1->next;
        ++cycle_len;
        if (cursor1 == start)
          break;
      }

      // Calculate the length of the path to 'start'
      cursor1 = head;
      int len1 = 0;
      while (cursor1 != start) {
        cursor1 = cursor1->next;
        ++len1;
      }

      // Reverse the direction of the cycle
      cursor1 = start;
      ListNode *next = cursor1->next;
      ListNode *nextnext = next->next;
      while (true) {
        next->next = cursor1;
        cursor1 = next;
        next = nextnext;
        nextnext = nextnext->next;
        if (cursor1 == start)
          break;
      }

      // Calculate the length of the path to 'start' after the cycle is reversed
      cursor1 = head;
      int len2 = 0;
      while (cursor1 != start) {
        cursor1 = cursor1->next;
        ++len2;
      }

      // Reverse the direction of the cycle back
      cursor1 = start;
      next = cursor1->next;
      nextnext = next->next;
      while (true) {
        next->next = cursor1;
        cursor1 = next;
        next = nextnext;
        nextnext = nextnext->next;
        if (cursor1 == start)
          break;
      }

      if (len1 == len2) {  // Case: the starting node is either 'start' or the absolute opposite of it.
        if (cycle_len % 2)  // No absolute opposite
          return start;

        int d = cycle_len / 2;
        ListNode *start2 = start;
        while (d--)
          start2 = start2->next;  // Get the absolute opposite

        cursor1 = head;
        while (true) {
          if (cursor1 == start)
            return start;
          if (cursor1 == start2)
            return start2;
          cursor1 = cursor1->next;
        }
      }

      // Assuming the real starting node is x, 'start' is y, distance from x to y is a, distance from y to x is b, distance from head to x is c
      // so a + b = cycle_len, c + a = len1, c + b = len2,
      // then c = (c + a) - ((a + b) + ((c + a) - (c + b))) / 2
      int target_idx = len1 - (cycle_len + (len1 - len2)) / 2;
      int idx = 0;
      cursor1 = head;
      while (idx < target_idx) {
        cursor1 = cursor1->next;
        ++idx;
      }
      return cursor1;
    }
};
