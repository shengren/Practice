import java.util.*;
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
    int[] inorder;
    int[] postorder;
    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
    
    TreeNode buildTree(int ia, int ib, int pa, int pb) {
        if (ia > ib || pa > pb) return null;
        TreeNode r = new TreeNode(postorder[pb]);
        int m = map.get(r.val);
        int l = m - ia;
        r.left = buildTree(ia, m - 1, pa, pa + l - 1);
        r.right = buildTree(m + 1, ib, pa + l, pb - 1);
        return r;
    }
    
    public TreeNode buildTree(int[] __inorder, int[] __postorder) {
        inorder = __inorder;
        postorder = __postorder;
        for (int i = 0; i < inorder.length; ++i) {
            map.put(inorder[i], i);
        }
        return buildTree(0, inorder.length - 1, 0, postorder.length - 1);
    }
}