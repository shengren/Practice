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
        ListNode ret = null;
        ListNode tail = null;
        ListNode prev = head;
        int ct = 1;
        ListNode cur = prev.next;
        while (cur != null) {
            if (cur.val == prev.val) {
                ++ct;
            } else {
                if (ct == 1) {
                    if (ret == null) {
                        ret = tail = prev;
                    } else {
                        tail.next = prev;
                        tail = tail.next;
                    }
                }
                prev = cur;
                ct = 1;
            }
            cur = cur.next;
        }
        if (ct == 1) {
            if (ret == null) {
                ret = tail = prev;
            } else {
                tail.next = prev;
                tail = tail.next;
            }
        }
        if (tail != null) tail.next = null;
        return ret;
    }
}