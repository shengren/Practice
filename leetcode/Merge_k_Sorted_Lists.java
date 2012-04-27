import java.util.*;
    
class Candidate implements Comparable {
    ListNode ln;
    int src;
    Candidate(ListNode _ln, int _src) {
        ln = _ln;
        src = _src;
    }
    public int compareTo(Object o) {
        Candidate c = (Candidate)o;
        //if (c1.ln.val == c2.ln.val) return c1.src - c2.src;
        return this.ln.val - c.ln.val;
    }
}

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
    public ListNode mergeKLists(ArrayList<ListNode> lists) {
        if (lists.size() == 0) return null;
        PriorityQueue<Candidate> queue = new PriorityQueue<Candidate>(lists.size());
        Object[] la = lists.toArray();
        ListNode[] l = new ListNode[la.length];
        for (int i = 0; i < l.length; ++i)
            l[i] = (ListNode)la[i];

        int n = l.length;
        for (int i = 0; i < l.length; ++i) {
            if (l[i] != null) {
                queue.add(new Candidate(l[i], i));
                l[i] = l[i].next;
            } else {
                --n;
            }
        }
        ListNode ret = null;
        ListNode cur = null;
        while (queue.size() > 0) {
            Candidate c = queue.poll();
            if (cur == null) {
                ret = cur = c.ln;
            } else {
                cur.next = c.ln;
                cur = cur.next;
            }
            if (l[c.src] != null) {
                if (n > 1) {
                    queue.add(new Candidate(l[c.src], c.src));
                    l[c.src] = l[c.src].next;
                } else {
                    while (l[c.src] != null) {
                        cur.next = l[c.src];
                        cur = cur.next;
                        l[c.src] = l[c.src].next;
                    }
                }
            } else {
                --n;
            }
        }
        return ret;
    }
}
