/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    TreeNode sortedListToBST(ListNode head, int n) {
        int m = n / 2;
        ListNode c = head;
        ListNode pre = null;
        int ct = 0;
        while (ct != m) {
            pre = c;
            c = c.next;
            ++ct;
        }
        TreeNode tn = new TreeNode(c.val);
        if (m > 0) {
            pre.next = null;
            tn.left = sortedListToBST(head, m);
        } else {
            tn.left = null;
        }
        if (m < n - 1) {
            tn.right = sortedListToBST(c.next, n - m - 1);
        } else {
            tn.right = null;
        }
        return tn;
    }
    
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null) return null;
        int n = 0;
        ListNode c = head;
        while (c != null) {
            ++n;
            c = c.next;
        }
        int m = n / 2;
        c = head;
        ListNode pre = null;
        int ct = 0;
        while (ct != m) {
            pre = c;
            c = c.next;
            ++ct;
        }
        TreeNode tn = new TreeNode(c.val);
        if (m > 0) {
            pre.next = null;
            tn.left = sortedListToBST(head, m);
        } else {
            tn.left = null;
        }
        if (m < n - 1) {
            tn.right = sortedListToBST(c.next, n - m - 1);
        } else {
            tn.right = null;
        }
        return tn;
    }
}
