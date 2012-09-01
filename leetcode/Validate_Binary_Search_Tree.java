import java.util.ArrayList;
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
    boolean isOK(TreeNode r, int l, int h) {
        if (r == null)
            return true;
        if (r.val <= l || r.val >= h)
            return false;
        return (isOK(r.left, l, r.val) && isOK(r.right, r.val, h));
    }
    public boolean isValidBST(TreeNode root) {
        return isOK(root, -987654321, 987654321);
    }
}
