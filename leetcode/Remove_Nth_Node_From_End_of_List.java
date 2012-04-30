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
        ListNode[] a = new ListNode[100];
        int x = 0;
        ListNode cur = head;
        while (cur != null) {
            a[x] = cur;
            x++;
            cur = cur.next;
        }
        int y = x - n;
        if (y == 0) head = head.next;
        else a[y - 1].next = a[y].next;
        return head;
    }
}