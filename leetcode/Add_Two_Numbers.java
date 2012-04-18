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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ret = null;
        ListNode cur = null;
        int c = 0;
        while (l1 != null && l2 != null) {
            int s = l1.val + l2.val + c;
            c = s / 10;
            if (cur == null) {
                ret = cur = new ListNode(s % 10);
            } else {
                cur.next = new ListNode(s % 10);
                cur = cur.next;
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        while (l1 != null) {
            int s = l1.val + c;
            c = s / 10;
            if (cur == null) {
                ret = cur = new ListNode(s % 10);
            } else {
                cur.next = new ListNode(s % 10);
                cur = cur.next;
            }
            l1 = l1.next;
        }
        while (l2 != null) {
            int s = l2.val + c;
            c = s / 10;
            if (cur == null) {
                ret = cur = new ListNode(s % 10);
            } else {
                cur.next = new ListNode(s % 10);
                cur = cur.next;
            }
            l2 = l2.next;
        }
        if (c > 0) {
            if (cur == null) {
                ret = cur = new ListNode(c);
            } else {
                cur.next = new ListNode(c);
                cur = cur.next;
            }
        }
        return ret;
    }
}
