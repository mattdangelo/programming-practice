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
    int best_diff = 0;
public:
    void recDFS(TreeNode* root, int small, int large) {
        int local_max_diff = std::max(std::abs(root->val - small), std::abs(root->val - large));
        if(local_max_diff > best_diff) {
            best_diff = local_max_diff;
        }

        if(root->left) {
            recDFS(root->left, std::min(small, root->val), std::max(large, root->val));
        }

        if(root->right) {
            recDFS(root->right, std::min(small, root->val), std::max(large, root->val));
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        recDFS(root, root->val, root->val);
        return best_diff;
    }
};
