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
    int current = 0;

    void DFS(TreeNode* root, int level) {
        current = current > level ? current : level;
        if(root->left != nullptr) {
            DFS(root->left, level + 1);
        }

        if(root->right != nullptr) {
            DFS(root->right, level + 1);
        }
    }
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        DFS(root, 1);
        return current;
    }
};