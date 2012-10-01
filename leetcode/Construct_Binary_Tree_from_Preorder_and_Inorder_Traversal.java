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
    int[] preorder;
    int[] inorder;
    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
    
    TreeNode buildTree(int pa, int pb, int ia, int ib) {
        if (pa > pb || ia > ib) return null;
        TreeNode r = new TreeNode(preorder[pa]);
        int m = map.get(r.val);
        int l = m - ia;
        r.left = buildTree(pa + 1, pa + l, ia, m - 1);
        r.right = buildTree(pa + l + 1, pb, m + 1, ib);
        return r;
    }
    
    public TreeNode buildTree(int[] __preorder, int[] __inorder) {
        preorder = __preorder;
        inorder = __inorder;
        for (int i = 0; i < inorder.length; ++i) {
            map.put(inorder[i], i);
        }
        return buildTree(0, preorder.length - 1, 0, inorder.length - 1);
    }
}