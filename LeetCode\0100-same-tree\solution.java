/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public static boolean isSameTree(TreeNode p, TreeNode q) {
        // Early exit
        if((p == null) != (q == null)) {
            return false;
        }
        else if(p == null) {
            return true;
        }

        return dfs(p, q);
    }

    public static boolean dfs(TreeNode p, TreeNode q) {
        if(p.val != q.val) {
            return false;
        }

        if(p.left != null) {
            if(q.left == null || q.left.val != p.left.val) {
                return false;
            }
            boolean result = dfs(p.left, q.left);
            if(!result) {
                return false;
            }
        }
        else if(q.left != null) {
            return false;
        }

        if(p.right != null) {
            if(q.right == null || q.right.val != p.right.val) {
                return false;
            }
            return dfs(p.right, q.right);
        }
        else return q.right == null;
    }
}
