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
    public ArrayList<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> ret = new ArrayList<Integer>();
        Stack<TreeNode> st = new Stack<TreeNode>();
        Stack<Boolean> ld = new Stack<Boolean>();
        if (root != null) {
            st.push(root);
            ld.push(false);
        }
        while (!st.empty()) {
            boolean f = ld.pop();
            if (!f) {
                ld.push(true);
                TreeNode t = st.peek();
                if (t.left != null) {
                    st.push(t.left);
                    ld.push(false);
                }
            } else {
                TreeNode t = st.pop();
                ret.add(t.val);
                if (t.right != null) {
                    st.push(t.right);
                    ld.push(false);
                }
            }
        }
        return ret;
    }
}