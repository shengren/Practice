import java.util.ArrayList;
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; left = null; right = null; }
 * }
 */
public class Solution {
    ArrayList<TreeNode> createTree(int a, int b) {
        ArrayList<TreeNode> ret = new ArrayList<TreeNode>();
        if (a > b) {
            ret.add(null);
            return ret;
        }

        for (int i = a; i <= b; ++i) {
            ArrayList<TreeNode> left_subtrees = createTree(a, i - 1);
            ArrayList<TreeNode> right_subtrees = createTree(i + 1, b);
            for (TreeNode lst : left_subtrees) {
                for (TreeNode rst : right_subtrees) {
                    TreeNode root = new TreeNode(i);
                    root.left = lst;
                    root.right = rst;
                    ret.add(root);
                }
            }
        }
        
        return ret;
    }
    
    public ArrayList<TreeNode> generateTrees(int n) {
        return createTree(1, n);
    }
}

