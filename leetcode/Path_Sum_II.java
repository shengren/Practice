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
    ArrayList<ArrayList<Integer>> ret;
    int sum;
    
    void dfs(TreeNode cn, int cs, ArrayList<Integer> path) {
        if (cn.left == null && cn.right == null) {
            if (cs == sum) {
                ArrayList<Integer> r = new ArrayList<Integer>(path);
                ret.add(r);
            }
            return;
        }
        if (cn.left != null) {
            path.add(cn.left.val);
            dfs(cn.left, cs + cn.left.val, path);
            path.remove(path.size() - 1);
        }
        if (cn.right != null) {
            path.add(cn.right.val);
            dfs(cn.right, cs + cn.right.val, path);
            path.remove(path.size() - 1);
        }
    }
    
    public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
        ret = new ArrayList<ArrayList<Integer>>();
        if (root == null) return ret;
        this.sum = sum;
        ArrayList<Integer> path = new ArrayList<Integer>();
        path.add(root.val);
        dfs(root, root.val, path);
        return ret;
    }
}