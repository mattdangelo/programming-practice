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
    public int max_depth = 1;

    public int maxDepth(TreeNode root) {

        if(root == null) {
            return 0;
        }

        dfs(root, 1);
        return max_depth;
    }

    public void dfs(TreeNode root, int depth) {
        max_depth = Math.max(max_depth, depth);
        if(root.left != null) {
            dfs(root.left, depth + 1);
        }

        if(root.right != null) {
            dfs(root.right, depth + 1);
        }
    }
}
