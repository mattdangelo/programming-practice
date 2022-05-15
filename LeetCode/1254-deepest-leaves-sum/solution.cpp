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
    int total = 0;
    int max_level = 0;

    void DFS(TreeNode* root, int level) {
        if(level == max_level) {
            total += root->val;
        }
        else if(level > max_level) {
            total = root->val;
            max_level = level;
        }

        if(root->left) {
            DFS(root->left, level + 1);
        }

        if(root->right) {
            DFS(root->right, level + 1);
        }
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        DFS(root, 0);
        return total;
    }
};
