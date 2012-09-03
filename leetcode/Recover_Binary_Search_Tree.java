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
    ArrayList<TreeNode> mo = null;
    
    void midOrderTraverse(TreeNode root) {
        if (root == null)
            return;
        midOrderTraverse(root.left);
        mo.add(root);
        midOrderTraverse(root.right);
    }
    
    public void recoverTree(TreeNode root) {
        mo = new ArrayList<TreeNode>();
        midOrderTraverse(root);
        TreeNode[] tn = mo.toArray(new TreeNode[mo.size()]);
        TreeNode a = null;
        for (int i = 0; i < tn.length; ++i) {
            if ((i > 0 && tn[i].val < tn[i - 1].val) ||
                (i < tn.length - 1 && tn[i].val > tn[i + 1].val)) {
                a = tn[i];
                break;
            }
        }
        TreeNode b = null;
        for (int i = tn.length - 1; i >= 0; --i) {
            if ((i > 0 && tn[i].val < tn[i - 1].val) ||
                (i < tn.length - 1 && tn[i].val > tn[i + 1].val)) {
                b = tn[i];
                break;
            }
        }
        int t = a.val;
        a.val = b.val;
        b.val = t;
    }
}