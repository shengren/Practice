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
    int max_height;
    void dfs(TreeNode t, int h) {
        if (t == null) return;
        if (h > max_height) max_height = h;
        dfs(t.left, h + 1);
        dfs(t.right, h + 1);
    }
    public int maxDepth(TreeNode root) {
        max_height = 0;
        dfs(root, 1);
        return max_height;
    }
}
