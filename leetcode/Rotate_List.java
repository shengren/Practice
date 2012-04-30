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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) return null;
        ListNode[] a = new ListNode[500];
        int k = 0;
        ListNode cur = head;
        while (cur != null) {
            a[k] = cur;
            k++;
            cur = cur.next;
        }
        n %= k;
        if (n > 0) {
            a[k - 1].next = a[0];
            a[k - n - 1].next = null;
            head = a[k - n];
        }
        return head;
    }
}