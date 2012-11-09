// TreeNode value could be negative. Good Problem.
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
    int res;
    int search(TreeNode r) {
        if (r == null) return 0;
        int ls = search(r.left);
        int rs = search(r.right);
        res = Math.max(res, Math.max(r.val, Math.max(r.val + ls, Math.max(r.val + rs, r.val + ls + rs))));
        return Math.max(r.val, Math.max(r.val + ls, r.val + rs));
    }
    public int maxPathSum(TreeNode root) {
        res = Integer.MIN_VALUE;
        search(root);
        return res;
    }
}
