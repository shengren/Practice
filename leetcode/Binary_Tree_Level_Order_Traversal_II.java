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
    public ArrayList<ArrayList<Integer>> levelOrderBottom(TreeNode root) {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        Queue<TreeNode>[] q = (Queue<TreeNode>[])new Queue[2];
        q[0] = new LinkedList<TreeNode>();
        if (root != null) {
            q[0].offer(root);
        }
        for (int i = 0; ; ++i) {
            int a = i % 2;
            int b = 1 - a;
            if (q[a].isEmpty()) break;
            q[b] = new LinkedList<TreeNode>();
            ArrayList<Integer> r = new ArrayList<Integer>();
            while (!q[a].isEmpty()) {
                TreeNode t = q[a].poll();
                r.add(t.val);
                if (t.left != null) q[b].offer(t.left);
                if (t.right != null) q[b].offer(t.right);
            }
            ret.add(0, r);
        }
        return ret;
    }
}
