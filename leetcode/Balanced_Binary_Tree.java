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
    boolean res;
    
    int depth(TreeNode t) {
        if (!res) return 0;
        if (t == null) return 0;
        int ld = depth(t.left);
        int rd = depth(t.right);
        if (Math.abs(ld - rd) > 1) {
            res = false;
        }
        return Math.max(ld, rd) + 1;
    }
    
    public boolean isBalanced(TreeNode root) {
        if (root == null) return true;
        res = true;
        depth(root);
        return res;
    }
}
