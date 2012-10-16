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
    public void flatten(TreeNode root) {
        if (root == null) return;
        Stack<TreeNode> s = new Stack<TreeNode>();
        TreeNode cn = root;
        while (true) {
            if (cn.left == null && cn.right == null) {
                if (!s.isEmpty())
                    cn = cn.right = s.pop();
                else
                    break;
            } else if (cn.left != null) {
                if (cn.right != null) s.push(cn.right);
                cn.right = cn.left;
                cn.left = null;
                cn = cn.right;
            } else {
                cn = cn.right;
            }
        }
    }
}
