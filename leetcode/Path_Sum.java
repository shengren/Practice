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
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) {
            return false;
        }
        Queue<TreeNode> nq = new LinkedList<TreeNode>();
        Queue<Integer> sq = new LinkedList<Integer>();
        nq.add(root);
        sq.add(root.val);
        while (!nq.isEmpty()) {
            TreeNode cn = nq.poll();
            int cs = sq.poll();
            if (cn.left == null && cn.right == null) {
                if (cs == sum) return true;
            }
            if (cn.left != null) {
                nq.add(cn.left);
                sq.add(cs + cn.left.val);
            }
            if (cn.right != null) {
                nq.add(cn.right);
                sq.add(cs + cn.right.val);
            }
        }
        return false;
    }
}