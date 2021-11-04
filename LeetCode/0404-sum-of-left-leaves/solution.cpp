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
    
    int DFS(TreeNode* root, bool came_from_left) {
        if(root->left == nullptr && root->right == nullptr) {
            return came_from_left ? root->val : 0;
        }

        int ret = 0;
        if(root->left != nullptr) {
            ret += DFS(root->left, true);
        }

        if(root->right != nullptr) {
            ret += DFS(root->right, false);
        }

        return ret;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return DFS(root, false);
    }
};
