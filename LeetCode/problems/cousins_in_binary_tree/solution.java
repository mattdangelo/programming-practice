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
    static class NodeInfo {
        int parent_val = -1;
        int level = -1;
        NodeInfo(int parent_val, int level) {
            this.parent_val = parent_val;
            this.level = level;
        }
    }

    static void DFS(TreeNode root, TreeNode prev, int level, HashMap<Integer, NodeInfo> nodeInfo) {
        nodeInfo.put(root.val, new NodeInfo(prev.val, level));
        if(root.left != null) {
            DFS(root.left, root, level + 1, nodeInfo);
        }

        if(root.right != null) {
            DFS(root.right, root, level + 1, nodeInfo);
        }
    }
    
    public boolean isCousins(TreeNode root, int x, int y) {
        HashMap<Integer, NodeInfo> nodeInfo = new HashMap<>();
        DFS(root, root, 0, nodeInfo);
        NodeInfo n_x = nodeInfo.get(x);
        NodeInfo n_y = nodeInfo.get(y);
        return (nodeInfo.get(x).level == nodeInfo.get(y).level) && n_x.parent_val != n_y.parent_val;
    }
}