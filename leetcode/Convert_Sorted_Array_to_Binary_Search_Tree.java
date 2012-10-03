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
    int[] num;
    
    TreeNode sortedArrayToBST(int a, int b) {
        if (a > b) return null;
        int m = a + (b - a + 1) / 2;
        TreeNode tn = new TreeNode(num[m]);
        tn.left = sortedArrayToBST(a, m - 1);
        tn.right = sortedArrayToBST(m + 1, b);
        return tn;
    }
    
    public TreeNode sortedArrayToBST(int[] __num) {
        num = __num;
        return sortedArrayToBST(0, num.length - 1);
    }
}
