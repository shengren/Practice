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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return null;
        ListNode prev = head;
        ListNode cur = prev.next;
        while (cur != null) {
            if (prev.val != cur.val) {
                prev.next = cur;
                prev = prev.next;
            }
            cur = cur.next;
        }
        prev.next = null;
        return head;
    }
}