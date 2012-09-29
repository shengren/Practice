import java.util.*;
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
    public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        ArrayList<TreeNode>[] l = (ArrayList<TreeNode>[])new ArrayList[2];
        l[0] = new ArrayList<TreeNode>();
        if (root != null) {
            l[0].add(root);
        }
        for (int i = 0; ; ++i) {
            int a = i % 2;
            int b = 1 - a;
            if (l[a].isEmpty()) break;
            l[b] = new ArrayList<TreeNode>();
            ArrayList<Integer> r = new ArrayList<Integer>();
            ListIterator<TreeNode> li = l[a].listIterator(l[a].size());
            while (li.hasPrevious()) {
                TreeNode t = li.previous();
                r.add(t.val);
                if (i % 2 == 0) {
                    if (t.left != null) l[b].add(t.left);
                    if (t.right != null) l[b].add(t.right);
                } else {
                    if (t.right != null) l[b].add(t.right);
                    if (t.left != null) l[b].add(t.left);
                }
            }
            ret.add(r);
        }
        return ret;
    }
}