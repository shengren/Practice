#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        stack<ListNode*> s;
        ListNode *tail = NULL;
        ListNode *cur = head;
        while (cur != NULL) {
            s.push(cur);
            cur = cur->next;
            if (s.size() == k) {
                ListNode *ln = s.top();
                s.pop();
                if (tail == NULL) {
                    head = ln;
                } else {
                    tail->next = ln;
                }
                tail = ln;
                while (!s.empty()) {
                    ln = s.top();
                    s.pop();
                    tail->next = ln;
                    tail = ln;
                }
                tail->next = cur;
            }
        }
        
        return head;
    }
};