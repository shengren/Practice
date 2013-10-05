/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
  public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      if (head == NULL)
        return NULL;

      RandomListNode *new_head = new RandomListNode(head->label);
      map<RandomListNode *, RandomListNode *> cache;
      cache[head] = new_head;

      RandomListNode *current = head;
      while (current != NULL) {
        RandomListNode *new_current = cache[current];

        if (current->next == NULL) {
          new_current->next = NULL;
        } else if (cache.find(current->next) != cache.end()) {
          new_current->next = cache[current->next];
        } else {
          RandomListNode *new_next = new RandomListNode(current->next->label);
          cache[current->next] = new_next;
          new_current->next = new_next;
        }

        if (current->random == NULL) {
          new_current->random = NULL;
        } else if (cache.find(current->random) != cache.end()) {
          new_current->random = cache[current->random];
        } else {
          RandomListNode *new_random = new RandomListNode(current->random->label);
          cache[current->random] = new_random;
          new_current->random = new_random;
        }

        current = current->next;
      }

      return new_head;
    }
};
