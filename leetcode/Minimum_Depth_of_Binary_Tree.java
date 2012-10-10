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
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        Queue<Integer> l = new LinkedList<Integer>();
        q.add(root);
        l.add(1);
        while (!q.isEmpty()) {
            TreeNode t = q.poll();
            int cl = l.poll();
            if (t.left == null && t.right == null) {
                return cl;
            }
            if (t.left != null) {
                q.add(t.left);
                l.add(cl + 1);
            }
            if (t.right != null) {
                q.add(t.right);
                l.add(cl + 1);
            }
        }
        return 0;
    }
}
