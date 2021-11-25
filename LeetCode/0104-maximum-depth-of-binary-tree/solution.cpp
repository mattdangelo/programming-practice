/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int DFS(TreeNode* n, int level) {
        if(n == nullptr) {
            return level;
        }

        return max( DFS(n->left, level + 1), DFS(n->right, level + 1));
    }
    
    int maxDepth(TreeNode* root) {
        return DFS(root, 0);
    }

};
