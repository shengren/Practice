import java.util.*;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode[] s = new ListNode[2];
        int ps = 0;
        ListNode cur = head;
        ListNode tail = null;
        while (cur != null) {
            s[ps++] = cur;
            cur = cur.next;
            if (ps == 2) {
                if (tail == null) {
                    head = tail = s[1];
                } else {
                    tail.next = s[1];
                    tail = tail.next;
                }
                tail.next = s[0];
                tail = tail.next;
                tail.next = cur;
                ps = 0;
            }
        }
        return head;
    }
}