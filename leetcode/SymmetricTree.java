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
    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;
        return isSymmetric(root.left, root.right);
    }
    boolean isSymmetric(TreeNode x, TreeNode y) {
        if (x == null && y == null) return true;
        if (x == null || y == null) return false;
        if (x.val != y.val) return false;
        return isSymmetric(x.left, y.right) && isSymmetric(x.right, y.left);
    }
}
