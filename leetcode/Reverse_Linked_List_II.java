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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (m == n) return head;
        int ct = 1;
        ListNode pre = null;
        ListNode cur = head;
        while (ct < m) {
            pre = cur;
            cur = cur.next;
            ++ct;
        }
        ListNode ml = pre;
        ListNode mr = cur;
        ListNode next = cur.next;
        while (ct < n) {
            pre = cur;
            cur = next;
            next = cur.next;
            cur.next = pre;
            ++ct;
        }
        if (ml == null) {
            ml = cur;
        } else {
            ml.next = cur;
        }
        mr.next = next;
        if (m == 1) return ml;
        return head;
    }
}