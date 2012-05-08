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
    public ListNode partition(ListNode head, int x) {
        ListNode head_a = null;
        ListNode head_b = null;
        ListNode tail_a = null;
        ListNode tail_b = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode cur_next = cur.next;
            if (cur.val < x) {
                if (tail_a == null) {
                    head_a = tail_a = cur;
                } else {
                    tail_a.next = cur;
                    tail_a = cur;
                }
                tail_a.next = null;
            } else {
                if (tail_b == null) {
                    head_b = tail_b = cur;
                } else {
                    tail_b.next = cur;
                    tail_b = cur;
                }
                tail_b.next = null;
            }
            cur = cur_next;
        }
        if (head_a == null) {
            return head_b;
        }
        tail_a.next = head_b;
        return head_a;
    }
}
